#pragma once

#define	SOUND_PARAM_NUM     2       // サウンドパラメータの種類数
#define	PROGRAM_NUM         5       // プログラム数


class CSuikaMain : public AudioEffectX {
public:
	CSuikaMain(audioMasterCallback audioMaster);
	virtual ~CSuikaMain(void);

	//// AudioEffectXからオーバーライド
	// イベント処理
	VstInt32 canDo(char* text);
	VstInt32 processEvents(VstEvents* events);

	// 信号処理
	void processReplacing(float** inputs, float** outputs, VstInt32 sampleFrames);
	void setSampleRate(float sampleRate);

	// プロパティ関連
	bool getEffectName(char* name);
	bool getVendorString(char* text);
	bool getProductString(char* text);
	VstInt32 getVendorVersion(void);

	// パラメータ関連
	void setParameter(VstInt32 index, float value);
	float getParameter(VstInt32 index);
	void getParameterName(VstInt32 index, char* text);
	void getParameterDisplay(VstInt32 index, char* text);

	// プログラム関連
	bool getProgramNameIndexed(VstInt32 category, VstInt32 index, char* text);
	void getProgramName(char* name);
	void setProgramName(char* name);
	void setProgram(VstInt32 program);
	VstInt32 getChunk(void** data, bool isPreset);
	VstInt32 setChunk (void* data, VstInt32 byteSize, bool isPreset);


};
