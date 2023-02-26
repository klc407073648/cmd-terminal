<template>
  <div style="margin: 8px 0; max-width: 600px">
    <a-card body-style="padding: 0 12px">
      <a-list item-layout="horizontal" :data-source="taskList">
        <template #renderItem="{ item, index }">
          <a-list-item>
            <template #actions>
              <a-button type="text" danger @click="doDelete(index)"
                >删除
              </a-button>
              <a-button type="text" danger @click="down()"
              >下载链接
              </a-button>
            </template>
            <a-list-item-meta>
              <template #title>
                {{ item.name }}
              </template>
              <template #description>
                创建时间：{{
                  MyDayjs(item.createTime).format("YYYY-MM-DD HH:mm:ss")
                }}
              </template>
              <template #avatar>
                <a-checkbox v-model:checked="item.isFinished" />
              </template>
            </a-list-item-meta>
          </a-list-item>
        </template>
      </a-list>
    </a-card>
  </div>
</template>

<script setup lang="ts">
import { toRefs } from "vue";
import { useTodoStore } from "./todoStore";
import MyDayjs from "../../../../plugins/myDayjs";

interface TodoBoxProps {
  today: boolean;
}

const props = withDefaults(defineProps<TodoBoxProps>(), {});
const { today } = toRefs(props);

const { taskList, deleteTask } = useTodoStore();

const doDelete = (index: number) => {
  deleteTask(index);
};

//下载文件
const downloadFile = () =>{
  let link = document.createElement('a');
  link.style.display = 'none';
  link.href = "https://stibel.icu/fire.mp4";//https://img.btstu.cn/api/images/5c67a69042609.jpg";
  link.download ="test";//下载文件名
  document.body.appendChild(link);
  link.click();
  document.body.removeChild(link) // 下载完成移除元素
};

const down = () => {
  //const url = 'https://img.btstu.cn/api/images/5c67a69042609.jpg'  //可以访问
  const url = 'https://stibel.icu/fire.mp4'  //xu需要解决跨域
  const filename = '操作指南'
  const x = new XMLHttpRequest()
  x.open('GET', url, true)
  x.responseType = 'blob'
  x.onload = e => {
    // 会创建一个 DOMString，其中包含一个表示参数中给出的对象的URL。这个 URL 的生命周期和创建它的窗口中的 document 绑定。这个新的URL 对象表示指定的 File 对象或 Blob 对象。
    const url = window.URL.createObjectURL(x.response)
    const a = document.createElement('a')
    a.href = url
    a.download = filename
    a.click()
  }
  x.send()
}
//下载文件

</script>

<style scoped></style>
