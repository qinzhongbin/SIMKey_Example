/*******************************************************************************
Copyright (C), 2018 Qasky Co., Ltd
File name:       qcard_error.h
Author:           Xinran Dai (daixinran@qasky.com)
Version:         1.0
Date:             2021/6/18
Description:   错误信息处理头文件
Others:          None
History:
Date                  Author            Version        Description
1. 2021/6/18      Xinran Dai       1.0               Create
*******************************************************************************/
#ifndef QCARD_ERROR_H
#define QCARD_ERROR_H

#ifdef _WIN32
#ifndef QERROR_API
#define QERROR_API __declspec(dllexport)
#endif
#else
#define QERROR_API 
#endif

#ifdef __cplusplus
extern "C" {
#endif  /* #ifdef  __cplusplus */

	void qcard_error_set_error(int error_code, char *error_info);

	QERROR_API int qcard_get_error_code();

	QERROR_API char* qcard_get_error_info();

#ifdef  __cplusplus
}
#endif  /* #ifdef  __cplusplus */

#endif /* #ifndef QCARD_ERROR_H */
