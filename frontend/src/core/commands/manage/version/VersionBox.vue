<template>
  <div>
    <div>版本信息：</div>
      <a-row >
        <a-col :span="4">前端版本</a-col>
        <a-col :span="4">V1.0</a-col>
      </a-row>
    <a-row >
      <a-col :span="4">后端版本</a-col>
      <a-col :span="4">V1.0</a-col>
    </a-row>
  </div>
</template>

<script setup lang="ts">
import { onMounted } from "vue";
import { shortcutList } from "../../../../components/cmd-terminal/shortcuts";

onMounted(() => {});
</script>

<style scoped></style>
