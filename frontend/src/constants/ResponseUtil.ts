import ResponseParamsType = ResponseType.ResponseParamsType;
import {AxiosError} from "axios";

/**
 * Axios返回的错误响应
 */

export const AXIOS_ERROR = "-1"

export function AxiosErrorResponse(code: string, data: any,err:AxiosError):ResponseParamsType{
    let tmp: ResponseParamsType ={
        code: code, // 返回码
        data: data, // 数据
        description: err?.message ,//描述
        message: err?.name, // 信息
    };
    return tmp;
}




