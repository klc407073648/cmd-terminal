import axios from "axios";

// 自定义 axios 实例
const myAxios = axios.create({
  baseURL:"/api",
  timeout: 3000
});

myAxios.defaults.withCredentials = true;

// 添加请求拦截器
myAxios.interceptors.request.use(
  function (config) {
    // 在发送请求之前做些什么
    return config;
  },
  function (error) {
    // 对请求错误做些什么
    console.log("添加请求拦截器error:"+error)
    return Promise.reject(error);
  }
);

// 添加响应拦截器
myAxios.interceptors.response.use(
  function (response) {
    console.log(response);
    //请求成功，无论是错误响应还是正确响应直接返回，由调用处理提示错误信息
    // 对响应数据做点什么
    return response.data;
  },
  function (error) {
    // 对响应错误做点什么
    //alert(error) //统一弹框处理
    console.log("响应拦截器error:"+error)
    return Promise.reject(error);
  }
);

export default myAxios;
