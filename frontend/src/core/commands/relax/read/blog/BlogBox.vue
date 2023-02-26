<template>
  <div>
    <div>博客列表：</div>
    <br>
    <div>公司技术博客：</div>
    <div v-for="(name, index) in Object.keys(techBlogList)" :key="index">
      <a-row :gutter="16">
        <a-col :span="4">{{ name }}</a-col>
        <a-col :span="4">
          <a :href="`${techBlogList[name]}`" target="_blank">
          {{ techBlogList[name] }}
          </a>
        </a-col>
      </a-row>
    </div>
    <br>
    <div>个人技术博客：</div>
    <div v-for="(name, index) in Object.keys(personBlogList)" :key="index">
      <a-row :gutter="16">
        <a-col :span="4">{{ name }}</a-col>
        <a-col :span="4">
          <a :href="`${personBlogList[name]}`" target="_blank">
            {{ personBlogList[name] }}
          </a>
        </a-col>
      </a-row>
    </div>
  </div>
</template>

<script setup lang="ts">
import { onMounted } from "vue";
import {CommandType} from "../../../../command";

//公司技术博客
const techBlogList: Record<string, string> = {
  "美团": "https://tech.meituan.com/",
  "有赞技术": "https://tech.youzan.com/",
  "Thoughtworks洞见": "https://insights.thoughtworks.cn/",
};

//个人技术博客
const personBlogList: Record<string, string> = {
  "C++ 全栈知识体系": "https://stibel.icu/",
  "Java 全栈知识体系": "https://www.pdai.tech/",
  "酷壳": "https://www.coolshell.cn/",
};


onMounted(() => {});
</script>

<style scoped></style>
