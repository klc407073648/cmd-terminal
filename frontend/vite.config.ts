import { defineConfig } from "vite";
import vue from "@vitejs/plugin-vue";
// @ts-ignore
import Components from "unplugin-vue-components/vite";
// @ts-ignore
import { AntDesignVueResolver } from "unplugin-vue-components/resolvers";
// @ts-ignore
import { chromeExtension } from "./build/chromeExtension";

// https://vitejs.dev/config/
export default defineConfig({
  plugins: [
    vue(),
    // 按需加载 ant-design-vue
    Components({
      resolvers: [AntDesignVueResolver()],
    }),
    process.env.BUILD_CRX && chromeExtension(),
  ].filter(Boolean),
  server:{
    proxy: {// 跨域代理
      '^/api': {
        // target: 'http://' + env.VUE_APP_BASE_API,
        // target: 'http://81.68.132.31:8082/api',
        target: 'http://$CMD_TERMINAL_BACKEND_IP:$CMD_TERMINAL_BACKEND_PORT/api', 
        changeOrigin: true,
        rewrite: (path) => path.replace(/^\/api/, '')
      },
  },
  }
});
