#pragma once

#define	SOUND_PARAM_NUM     2       // �T�E���h�p�����[�^�̎�ސ�
#define	PROGRAM_NUM         5       // �v���O������


class CSuikaMain : public AudioEffectX {
public:
	CSuikaMain(audioMasterCallback audioMaster);
	virtual ~CSuikaMain(void);

	//// AudioEffectX����I�[�o�[���C�h
	// �C�x���g����
	VstInt32 canDo(char* text);
	VstInt32 processEvents(VstEvents* events);

	// �M������
	void processReplacing(float** inputs, float** outputs, VstInt32 sampleFrames);
	void setSampleRate(float sampleRate);

	// �v���p�e�B�֘A
	bool getEffectName(char* name);
	bool getVendorString(char* text);
	bool getProductString(char* text);
	VstInt32 getVendorVersion(void);

	// �p�����[�^�֘A
	void setParameter(VstInt32 index, float value);
	float getParameter(VstInt32 index);
	void getParameterName(VstInt32 index, char* text);
	void getParameterDisplay(VstInt32 index, char* text);

	// �v���O�����֘A
	bool getProgramNameIndexed(VstInt32 category, VstInt32 index, char* text);
	void getProgramName(char* name);
	void setProgramName(char* name);
	void setProgram(VstInt32 program);
	VstInt32 getChunk(void** data, bool isPreset);
	VstInt32 setChunk (void* data, VstInt32 byteSize, bool isPreset);


};
