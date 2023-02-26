<template>
  <cmd-terminal
    ref="terminalRef"
    :user="loginUser"
    full-screen
    :on-submit-command="onSubmitCommand"
  />
</template>

<script setup lang="ts">
import { doCommandExecute } from "../core/commandExecutor";
import { onMounted, ref } from "vue";
import { useUserStore } from "../core/commands/manage/user/userStore";
import { storeToRefs } from "pinia";
import {writeUserLog} from "../core/commands/manage/authority/authorityApi";

const terminalRef = ref();

const onSubmitCommand = async (inputText: string) => {
  const terminal = terminalRef.value.terminal;

  //记录用户日志
  await writeUserLog(inputText,terminal)

  console.log('进来执行 onSubmitCommand in')
  if (!inputText) {
    return;
  }

  await doCommandExecute(inputText, terminal);
};

const userStore = useUserStore();
const { loginUser } = storeToRefs(userStore);

onMounted(() => {
  userStore.getAndSetLoginUser();
});
</script>

<style></style>
