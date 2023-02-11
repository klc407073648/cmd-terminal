<template>
  <div>
    <div>
       命令集 {{name}}
    </div>
    <div>命令列表：</div>
    <div v-for="(command, index) in cmdSets" :key="index">
      <a-row :gutter="16">
        <a-col :span="4">{{ cmdSets[index].func }}</a-col>
        <a-col :span="4">{{ cmdSets[index].name }}</a-col>
        <a-col>{{ cmdSets.desc }}</a-col>
      </a-row>
      <div v-if="cmdSets[index].subCommands" style="text-indent:2em;">  子命令列表：</div>
      <div v-for="(subcommand, index1) in cmdSets[index].subCommands" :key="index1" style="text-indent:2em;">
        <a-row :gutter="16">
          <a-col :span="4" >{{ (cmdSets[index].subCommands)[index1].func  }}</a-col>
          <a-col :span="4">{{ (cmdSets[index].subCommands)[index1].name }}</a-col>
        </a-row>
      </div>
    </div>
  </div>
</template>

<script setup lang="ts">
  import {onMounted, toRefs} from "vue";
  import { commandList } from "../../commandRegister";
  import {CommandType} from "../../command";

  interface SetInfoBoxProps {
    name: string;
    cmdSets: Record<string, CommandType>;
  }

  const props = withDefaults(defineProps<SetInfoBoxProps>(), {});
  const { name,cmdSets } = toRefs(props);

  onMounted(() => {});
</script>

<style scoped></style>
