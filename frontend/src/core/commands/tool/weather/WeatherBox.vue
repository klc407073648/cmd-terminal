<template>
    <div v-if="!curInfo?.casts">
        <a-row :gutter="[16,8]">
            <a-col :span="8" :offset="1">{{curInfo.province}}:{{curInfo.city}}</a-col>
            <a-col :span="8">天气: {{curInfo.weather}}</a-col>
        </a-row>
        <a-divider style="background-color: #7cb305"/>
        <a-row>
            <a-col :span="8" :offset="1">当前气温: {{curInfo.temperature}}</a-col>
        </a-row>
        <a-row>
            <a-col :span="8" :offset="1">风向: {{curInfo.winddirection}}</a-col>
        </a-row>
        <a-row>
            <a-col :span="8" :offset="1">风力等级: {{curInfo.windpower}}</a-col>
        </a-row>
        <a-row>
            <a-col :span="8" :offset="1">空气湿度: {{curInfo.humidity}}%</a-col>
        </a-row>
        <a-row>
            <a-col :span="8" :offset="1">更新时间: {{curInfo.reporttime}}</a-col>
        </a-row>
    </div>
    <div v-if="curInfo?.casts">
        <a-row>{{curInfo.province}}:{{curInfo.city}}</a-row>
        <a-row>
            <div v-for="(_, index) in curInfo.casts" :key="index">
                <a-col>
                    <a-card :title="curInfo.casts[index].date + getDay(curInfo.casts[index].week)" :bordered="false">
                        <p>白天天气: {{curInfo.casts[index].dayweather}}</p>
                        <p>夜间天气: {{curInfo.casts[index].nightweather}}</p>
                        <p>白天温度: {{curInfo.casts[index].daytemp_float}}</p>
                        <p>夜间温度: {{curInfo.casts[index].nighttemp_float}}</p>
                    </a-card>
                </a-col>
            </div>
        </a-row>
    </div>
</template>

<script setup lang="ts">
    import {onMounted, toRefs} from "vue";

    interface WeatherBoxProps {
        weatherInfo: string;
    }

    const props = withDefaults(defineProps<WeatherBoxProps>(), {});
    const {weatherInfo} = toRefs(props);

    const curInfo = weatherInfo.value[0];

    function getDay(num: string): string {
        switch (num) {
            case "1":
                return "星期一";
            case "2":
                return "星期二";
            case "3":
                return "星期三";
            case "4":
                return "星期四";
            case "5":
                return "星期五";
            case "6":
                return "星期六";
            case "7":
                return "星期日";
        }
        return ""
    };
    console.log("curInfo:", curInfo)
    onMounted(() => {
    });
</script>

<style scoped>
</style>
