#include <pluginterfaces/vst2.x/aeffect.h>
#include <public.sdk/source/vst2.x/audioeffectx.h>
#include <public.sdk/source/vst2.x/aeffeditor.h>
#include <windows.h>

#include "SuikaMain.h"

#include <public.sdk\source\vst2.x\audioeffect.cpp>
#include <public.sdk\source\vst2.x\audioeffectx.cpp>
#include <public.sdk\source\vst2.x\vstplugmain.cpp>

// VST�I�u�W�F�N�g�̐����֐�
AudioEffect *createEffectInstance(audioMasterCallback audioMaster) {
    // �N���X����
    return new CSuikaMain(audioMaster);
}

// 

CSuikaMain::CSuikaMain(audioMasterCallback audioMaster) : AudioEffectX(audioMaster, PROGRAM_NUM, SOUND_PARAM_NUM) {


}


//
CSuikaMain::~CSuikaMain() {
}

// **** �v���O�C������
bool CSuikaMain::getEffectName(char *name) {
    vst_strncpy(name, "SuikaMain", kVstMaxEffectNameLen);
    return true;
}

// **** �x���_�[����
bool CSuikaMain::getVendorString(char *text) {
    vst_strncpy(text, "VSTSuikaProject", kVstMaxVendorStrLen);
    return true;
}

// **** �v���O�C���Ɋւ���e�L�X�g
bool CSuikaMain::getProductString(char *text) {
    vst_strncpy(text, "Vst Suika Project", kVstMaxVendorStrLen);
    return true;
}

// **** �ŗL�o�[�W����
VstInt32 CSuikaMain::getVendorVersion() {
    return 1000;
}

// **** �T�|�[�g�@�\��Ԃ�
VstInt32 CSuikaMain::canDo(char *text) {
    if (!strcmp(text, "receiveVstEvents"))      return 1;
    if (!strcmp(text, "receiveVstMidiEvent"))   return 1;
    return -1;
}

// **** MIDI�C�x���g��M
VstInt32 CSuikaMain::processEvents(VstEvents *ev) {
    return 1;
}

// **** �M������
void CSuikaMain::processReplacing(float **inputs, float **outputs, VstInt32 sampleFrames) {
}

// **** �T���v�����O���[�g�ݒ�
void CSuikaMain::setSampleRate(float sampleRate) {
    AudioEffectX::setSampleRate(sampleRate);
}

// **** �z�X�g����̃V���Z�p�����[�^�ݒ�
void CSuikaMain::setParameter(VstInt32 index, float value) {
}

// **** �z�X�g����̃V���Z�p�����[�^�v��
float CSuikaMain::getParameter(VstInt32 index) {
    return 0.f;
}

// **** �p�����[�^���v��
void CSuikaMain::getParameterName(VstInt32 index, char *text) {
    vst_strncpy(text, "PmNSuika", kVstMaxParamStrLen);
}

// **** �p�����[�^�l�Ή��e�L�X�g�v��
void CSuikaMain::getParameterDisplay(VstInt32 index, char *text) {
    vst_strncpy(text, "PmDSuika", kVstMaxParamStrLen);
}

// **** �v���O�������v��
bool CSuikaMain::getProgramNameIndexed(VstInt32 category, VstInt32 index, char *name) {
    if (index < 0 || index >= PROGRAM_NUM) return false;
    vst_strncpy(name, "PgNISuika", kVstMaxProgNameLen);
    return true;
}

// **** �J�����g�v���O�������v��
void CSuikaMain::getProgramName(char *name) {
    vst_strncpy(name, "PgNCSuika", kVstMaxProgNameLen);
}

// **** �J�����g�v���O�����ύX
void CSuikaMain::setProgramName(char *name) {
}

// **** �v���O�����ύX
void CSuikaMain::setProgram(VstInt32 program) {
}

// **** �p�b�`���v��
VstInt32 CSuikaMain::getChunk(void **data, bool isPreset) {
    return 0;
}

// **** �p�b�`���ݒ�v��
VstInt32 CSuikaMain::setChunk(void *data, VstInt32 byteSize, bool isPreset) {
    return 1;
}


