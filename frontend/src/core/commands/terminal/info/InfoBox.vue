<template>
  <div>关于本站：cmdTerminal 极客范儿的浏览器主页</div>
  <div>
    <a :href="project_link" target="_blank">
      代码开源，欢迎 star 和贡献~
    </a>
  </div>
  <div></div>
  <div>
    作者：
    <a :href="project_profile" target="_blank">
      klc
    </a>
  </div>
</template>

<script setup lang="ts">

import {project_link,project_profile} from "../../../../constants/globalVar";
interface InfoBoxProps {
  seconds: string;
}

const props = withDefaults(defineProps<InfoBoxProps>(), {});
</script>

<style scoped></style>
