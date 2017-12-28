#pragma once

#include "SpeechTask.h"

void FSpeechTask::DoWork()
{
	int ret = MSP_SUCCESS;
	const char* login_params = "appid = 5a43b8d9, work_dir = .";	// ��¼������appid��msc��󶨣���������Ķ�

																	/*
																	* sub:				����ҵ������
																	* domain:			����
																	* language:			����
																	* accent:			����
																	* sample_rate:		��Ƶ������
																	* result_type:		ʶ������ʽ
																	* result_encoding:	��������ʽ
																	*
																	*/
	const char* session_begin_params = "engine_type = mixed, sub = iat, ptt = 0, domain = iat, language = zh_cn, accent = mandarin, sample_rate = 16000, result_type = json, result_encoding = UTF-8";

	/* �û���¼ */
	ret = MSPLogin(NULL, NULL, login_params); //��һ���������û������ڶ������������룬����NULL���ɣ������������ǵ�¼����	
	if (MSP_SUCCESS != ret) {
		UE_LOG(SnowingError, Error, TEXT("MSPLogin failed , Error code %d.\n"), ret);
		goto exit; //��¼ʧ�ܣ��˳���¼
	}

	xunfeispeech->speech_mic(session_begin_params);

exit:
	MSPLogout(); //�˳���¼

	return;

}