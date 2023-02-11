import axios from "axios";

// 自定义 axios 实例
const myAxios = axios.create({
  baseURL:
    // @ts-ignore
    process.env.NODE_ENV === "production"
      ? "https://PROD_ADDRESS:7345/api"
      : "http://localhost:7345/api",
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
