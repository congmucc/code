import { UserConfigExport, ConfigEnv, loadEnv } from 'vite'
import { warpperEnv } from './build'
import { getPluginsList } from './build/plugins'
import { include, exclude } from './build/optimize'
import { resolve } from 'path'

/** 当前执行node命令时文件夹的地址（工作目录） */
const root: string = process.cwd()

/** 路径查找 */
const pathResolve = (dir: string): string => {
	return resolve(__dirname, '.', dir)
}

/** 设置别名 */
const alias: Record<string, string> = {
	'@': pathResolve('src')
}

// vite官网
// https://vitejs.dev/config/

export default ({ mode }: ConfigEnv): UserConfigExport => {
	const { VITE_PORT, VITE_PUBLIC_PATH } = warpperEnv(loadEnv(mode, root))
	return {
		base: VITE_PUBLIC_PATH,
		root,
		resolve: {
			alias
		},
		// 服务端渲染
		server: {
			// 是否开启 https
			// 端口号
			port: VITE_PORT,
			host: '0.0.0.0',
			// 本地跨域代理 https://cn.vitejs.dev/config/server-options.html#server-proxy
			proxy: {
				'/zyb': {
					// 这里填写后端地址
					target: 'http://127.0.0.1:8090',
					changeOrigin: true,
					rewrite: (path) => path.replace(/^\/zyb/, '')
				}
			}
		},
		plugins: getPluginsList(),
		// https://cn.vitejs.dev/config/dep-optimization-options.html#dep-optimization-options
		optimizeDeps: {
			include,
			exclude
		}
	}
}
