// 定义请求的根路径
const baseUrl="http://localhost:8080";
let ajaxTiems=0;


/**
 * 返回请求根路baseUrl
 * @param {*} params 
 */
export const getBaseUrl=() =>{
  return baseUrl;
}

/**
 * wx login封装
 * @param {*} params 
 */
export const getWxLogin=()=>{
  return new Promise((resolve, reject)=>{
    wx.login({
      timeout: 5000,
      success: (res) => {
        resolve(res)
      },
      fail: (err) => {
        reject(err)
      }
    })
  })
}

/**
 * wx getUserProfile封装
 * @param {*} params 
 */
export const getUserProfile=() =>{
  return new Promise((resolve, reject)=>{
    wx.getUserProfile({
      desc: '获取用户信息',
      success: (res) => {
        resolve(res)
      },
      fail: (err)=>{
        reject(err)
      }
    })
    })
}



/**
 * 后端请求工具类
 * @param {*} params 
 */
export const requestUtil=(params)=>{
  let header = wx.getStorageSync('openid') ? ({'token':wx.getStorageSync('openid').token}) : {};
  const newHeader = {...header, ...params.header}
  var start = new Date().getTime();
  ajaxTiems++;
  // 加载中
  wx.showLoading({
    title: '加载中...',
    mask:'true'
  })

  // 模拟网络延迟
  while(true){
    if(new Date().getTime()-start>100)break;
  }

  return new Promise((resolve, reject)=>{
    wx.request({
      ...params,
      header:newHeader,
      url: baseUrl+params.url,
      success: (res)=> {
        resolve(res)
      },
      fail: (err)=> {
        reject(err)
      },
      complete:()=>{
        ajaxTiems--;
        if(ajaxTiems === 0){
          wx.hideLoading();
        }
      }
    })
  });
}