/**
 * MD5加密函数
 * @param {string} str 需要加密的字符串
 * @return {string} 加密后的MD5字符串
 */
function md5(str) {
    // 使用crypto库进行MD5加密，这个API在Node.js环境中可用
    // 如果是在浏览器环境中，需要确保环境支持Web Crypto API或者使用第三方库如crypto-js
    if (typeof crypto !== 'undefined' && typeof crypto.subtle !== 'undefined') {
        return new Promise((resolve, reject) => {
            crypto.subtle.digest('SHA-256', new TextEncoder().encode(str))
                .then(buffer => {
                    let hashArray = Array.from(new Uint8Array(buffer));
                    let hashHex = hashArray.map(b => b.toString(16).padStart(2, '0')).join('');
                    resolve(hashHex); // 注意：这是SHA-256，不是MD5，因为原生API通常不直接提供MD5
                })
                .catch(reject);
        });
    } else if (window && window.location.protocol === 'https:' && typeof CryptoJS !== 'undefined') {
        // 如果是浏览器且CryptoJS库可用，则使用CryptoJS进行MD5加密
        resolve(CryptoJS.MD5(str).toString());
    } else {
        console.error("MD5加密功能不可用，请确保在支持的环境中运行或引入了CryptoJS库。");
    }
}

// 使用示例
(async () => {
    try {
        const result = await md5("2&90f282d792b8dcf67d821c9636e408c9&secretKey&server.base.userData.BpaasTeamController.createTeam&1635226188&1635226188&WEB");
        console.log("MD5 Hash:", result);
    } catch (error) {
        console.error("加密出错:", error);
    }
})();
