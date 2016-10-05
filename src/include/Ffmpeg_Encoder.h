#pragma once


#include "stdafx.h"
#define __FFMPEG_ENCODER__

#define MAX_INFO_SIZE 2048

#ifdef __FFMPEG_ENCODER__
#ifdef	__cplusplus
extern "C"
{
#endif
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavdevice/avdevice.h"
#include "libavutil/audio_fifo.h"
#include "libavfilter/avfilter.h"

#pragma comment(lib, "avcodec.lib")
#pragma comment(lib, "avformat.lib")
#pragma comment(lib, "avutil.lib")
#pragma comment(lib, "avdevice.lib")
#pragma comment(lib, "avfilter.lib")

#pragma comment(lib, "swscale.lib")
#ifdef __cplusplus
};
#endif


class Ffmpeg_Encoder
{
protected:
#if 1
	AVFormatContext	*pFormatCtx_Video = NULL, *pFormatCtx_Audio = NULL, *pFormatCtx_Out = NULL;
	AVCodecContext	*pCodecCtx_Video;
	AVCodec			*pCodec_Video;
	AVFifoBuffer	*fifo_video = NULL;
	AVAudioFifo		*fifo_audio = NULL;
	int VideoIndex, AudioIndex;

	CRITICAL_SECTION AudioSection, VideoSection;
#endif

public:
	Ffmpeg_Encoder();
	~Ffmpeg_Encoder();

public:
#if 1
	AVFrame *m_pRGBFrame;   //֡����  
	AVFrame *m_pYUVFrame;   //֡����  
	AVCodec *pCodecH264;    //������  
	AVCodecContext *c;      //���������ݽṹ����  
	uint8_t *yuv_buff;      //yuvͼ��������  
	uint8_t *rgb_buff;      //rgbͼ��������  
	SwsContext *scxt;       //ͼ���ʽת������  
	uint8_t *outbuf;        //���������Ƶ���ݻ���  
	int outbuf_size;        //�����������ȥ��С  
	int nDataLen;           //rgbͼ������������  
	int width;              //�����Ƶ���  
	int height;             //�����Ƶ�߶�  
//	avpacket pkt;            //���ݰ��ṹ��
#endif

public:
	int Ffmpeg_Encoder_Init();//��ʼ��  
	//void Ffmpeg_Encoder_Setpara(CodecID mycodeid, int vwidth, int vheight);//���ò���,��һ������Ϊ������,�ڶ�������Ϊѹ����������Ƶ�Ŀ�ȣ���������Ƶ��Ϊ��߶�  
	int Ffmpeg_Encoder_Encode(FILE *file, uint8_t *data);//���벢д�����ݵ��ļ�  
	int Ffmpeg_Encoder_Close();//�ر�

	char* urlprotocolinfo();
	char* avformatinfo();
	char* avcodecinfo();
	char* avfilterinfo();
	char* configurationinfo();

	void get_encoder_info();

};

#endif
