#include "stdafx.h"
#include "include/Ffmpeg_Encoder.h"

#ifdef __FFMPEG_ENCODER__
Ffmpeg_Encoder::Ffmpeg_Encoder()
{
}


Ffmpeg_Encoder::~Ffmpeg_Encoder()
{
}


int Ffmpeg_Encoder::Ffmpeg_Encoder_Init()//初始化
{
	printf("[%s]",__func__);
	return 0;
}
#if 0
int Ffmpeg_Encoder::Ffmpeg_Encoder_Setpara(CodecID mycodeid, int vwidth, int vheight);//设置参数,第一个参数为编码器,第二个参数为压缩出来的视频的宽度，第三个视频则为其高度  
{
	printf("[%s]", __func__);
	return 0;
}
#endif

int Ffmpeg_Encoder::Ffmpeg_Encoder_Encode(FILE *file, uint8_t *data)//编码并写入数据到文件  
{
	printf("[%s]", __func__);
	return 0;
}
int Ffmpeg_Encoder::Ffmpeg_Encoder_Close()//关闭
{
	printf("[%s]", __func__);
	return 0;
}


char* Ffmpeg_Encoder::urlprotocolinfo()
{
	char *info = (char *)malloc(40000);
	printf("---------->>Enter <%s><<---------------\n", __func__);
	memset(info, 0, 40000);
	av_register_all();

	struct URLProtocol *pup = NULL;
	//Input  
	struct URLProtocol **p_temp = &pup;
	avio_enum_protocols((void **)p_temp, 0);
	while ((*p_temp) != NULL) {
		sprintf(info, "%s[In ][%10s]\n", info, avio_enum_protocols((void **)p_temp, 0));
	}
	pup = NULL;
	//Output  
	avio_enum_protocols((void **)p_temp, 1);
	while ((*p_temp) != NULL) {
		sprintf(info, "%s[Out][%10s]\n", info, avio_enum_protocols((void **)p_temp, 1));
	}

	printf("---------->>Exit <%s><<---------------\n", __func__);
	return info;

}




char * Ffmpeg_Encoder::avformatinfo()
{
	char *info = (char *)malloc(40000);
	printf("---------->>Enter <%s><<---------------\n", __func__);
	memset(info, 0, 40000);

	av_register_all();

	AVInputFormat *if_temp = av_iformat_next(NULL);
	AVOutputFormat *of_temp = av_oformat_next(NULL);
	//Input  
	while (if_temp != NULL) {
		sprintf(info, "%s[In ] %10s\n", info, if_temp->name);
		if_temp = if_temp->next;
	}
	//Output  
	while (of_temp != NULL) {
		sprintf(info, "%s[Out] %10s\n", info, of_temp->name);
		of_temp = of_temp->next;
	}
	printf("---------->>Exit <%s><<---------------\n", __func__);
	return info;
}

/**
* AVCodec Support Information
*/
char* Ffmpeg_Encoder::avcodecinfo()
{
	char *info = (char *)malloc(40000);
	printf("---------->>Enter <%s><<---------------\n", __func__);
	memset(info, 0, 40000);

	av_register_all();

	AVCodec *c_temp = av_codec_next(NULL);

	while (c_temp != NULL) {
		if (c_temp->decode != NULL) {
			sprintf(info, "%s[Dec]", info);
		}
		else {
			sprintf(info, "%s[Enc]", info);
		}
		switch (c_temp->type) {
		case AVMEDIA_TYPE_VIDEO:
			sprintf(info, "%s[Video]", info);
			break;
		case AVMEDIA_TYPE_AUDIO:
			sprintf(info, "%s[Audio]", info);
			break;
		default:
			sprintf(info, "%s[Other]", info);
			break;
		}

		sprintf(info, "%s %10s\n", info, c_temp->name);

		c_temp = c_temp->next;
	}
	printf("---------->>Exit <%s><<---------------\n", __func__);
	return info;
}

/**
* AVFilter Support Information
*/
char* Ffmpeg_Encoder::avfilterinfo()
{
	char *info = (char *)malloc(40000);
	printf("---------->>Enter <%s><<---------------\n", __func__);
	memset(info, 0, 40000);

	avfilter_register_all();

	AVFilter *f_temp = (AVFilter *)avfilter_next(NULL);

	while (f_temp != NULL) {
		sprintf(info, "%s[%15s]\n", info, f_temp->name);
		f_temp = f_temp->next;
	}
	printf("---------->>Exit <%s><<---------------\n", __func__);
	return info;
}

/**
* Configuration Information
*/
char* Ffmpeg_Encoder::configurationinfo()
{
	char *info = (char *)malloc(40000);
	printf("---------->>Enter <%s><<---------------\n", __func__);
	memset(info, 0, 40000);

	av_register_all();

	sprintf(info, "%s\n", avcodec_configuration());
	printf("---------->>Exit <%s><<---------------\n", __func__);
	return info;
}


void Ffmpeg_Encoder::get_encoder_info()
{
	char* info;
	info = (char*)malloc(MAX_INFO_SIZE);
	memset(info, 0x0, MAX_INFO_SIZE);
	info = urlprotocolinfo();
	printf("urlprotocolinfo Info:\n%s\n",info);

	memset(info, 0x0, MAX_INFO_SIZE);
	info = avformatinfo();
	printf("avformatinfo Info:\n%s\n", info);
	memset(info, 0x0, MAX_INFO_SIZE);
	info = avcodecinfo();
	printf("avcodecinfo Info:\n%s\n", info);
	memset(info, 0x0, MAX_INFO_SIZE);
	info = avfilterinfo();
	printf("avfilterinfo Info:\n%s\n", info);
	memset(info, 0x0, MAX_INFO_SIZE);
	info = configurationinfo();
	printf("configurationinfo Info:\n%s\n", info);

	free(info);

	//printf("Get info: -->%s<--", info);

}



#endif


