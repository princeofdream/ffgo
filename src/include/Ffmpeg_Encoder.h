#pragma once


#include "stdafx.h"

//#define __FFMPEG_ENCODER__

#if 0
#ifdef	__cplusplus
extern "C"
{
#endif
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavdevice/avdevice.h"
#include "libavutil/audio_fifo.h"

#pragma comment(lib, "avcodec.lib")
#pragma comment(lib, "avformat.lib")
#pragma comment(lib, "avutil.lib")
#pragma comment(lib, "avdevice.lib")
#pragma comment(lib, "avfilter.lib")

	//#pragma comment(lib, "avfilter.lib")
	//#pragma comment(lib, "postproc.lib")
	//#pragma comment(lib, "swresample.lib")
#pragma comment(lib, "swscale.lib")
#ifdef __cplusplus
};
#endif

AVFormatContext	*pFormatCtx_Video = NULL, *pFormatCtx_Audio = NULL, *pFormatCtx_Out = NULL;
AVCodecContext	*pCodecCtx_Video;
AVCodec			*pCodec_Video;
AVFifoBuffer	*fifo_video = NULL;
AVAudioFifo		*fifo_audio = NULL;
int VideoIndex, AudioIndex;

CRITICAL_SECTION AudioSection, VideoSection;


class Ffmpeg_Encoder
{
public:
	Ffmpeg_Encoder();
	~Ffmpeg_Encoder();

public:
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

public:
	void Ffmpeg_Encoder_Init();//��ʼ��  
//	void Ffmpeg_Encoder_Setpara(CodecID mycodeid, int vwidth, int vheight);//���ò���,��һ������Ϊ������,�ڶ�������Ϊѹ����������Ƶ�Ŀ�ȣ���������Ƶ��Ϊ��߶�  
	void Ffmpeg_Encoder_Encode(FILE *file, uint8_t *data);//���벢д�����ݵ��ļ�  
	void Ffmpeg_Encoder_Close();//�ر�
};

#endif
