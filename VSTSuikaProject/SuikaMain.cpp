#include <pluginterfaces/vst2.x/aeffect.h>
#include <public.sdk/source/vst2.x/audioeffectx.h>
#include <public.sdk/source/vst2.x/aeffeditor.h>
#include <windows.h>

#include "SuikaMain.h"

#include <public.sdk\source\vst2.x\audioeffect.cpp>
#include <public.sdk\source\vst2.x\audioeffectx.cpp>
#include <public.sdk\source\vst2.x\vstplugmain.cpp>

// VSTオブジェクトの生成関数
AudioEffect *createEffectInstance(audioMasterCallback audioMaster) {
    // クラス生成
    return new CSuikaMain(audioMaster);
}

// 

CSuikaMain::CSuikaMain(audioMasterCallback audioMaster) : AudioEffectX(audioMaster, PROGRAM_NUM, SOUND_PARAM_NUM) {


}


//
CSuikaMain::~CSuikaMain() {
}

// **** プラグイン名称
bool CSuikaMain::getEffectName(char *name) {
    vst_strncpy(name, "SuikaMain", kVstMaxEffectNameLen);
    return true;
}

// **** ベンダー名称
bool CSuikaMain::getVendorString(char *text) {
    vst_strncpy(text, "VSTSuikaProject", kVstMaxVendorStrLen);
    return true;
}

// **** プラグインに関するテキスト
bool CSuikaMain::getProductString(char *text) {
    vst_strncpy(text, "Vst Suika Project", kVstMaxVendorStrLen);
    return true;
}

// **** 固有バージョン
VstInt32 CSuikaMain::getVendorVersion() {
    return 1000;
}

// **** サポート機能を返す
VstInt32 CSuikaMain::canDo(char *text) {
    if (!strcmp(text, "receiveVstEvents"))      return 1;
    if (!strcmp(text, "receiveVstMidiEvent"))   return 1;
    return -1;
}

// **** MIDIイベント受信
VstInt32 CSuikaMain::processEvents(VstEvents *ev) {
    return 1;
}

// **** 信号処理
void CSuikaMain::processReplacing(float **inputs, float **outputs, VstInt32 sampleFrames) {
}

// **** サンプリングレート設定
void CSuikaMain::setSampleRate(float sampleRate) {
    AudioEffectX::setSampleRate(sampleRate);
}

// **** ホストからのシンセパラメータ設定
void CSuikaMain::setParameter(VstInt32 index, float value) {
}

// **** ホストからのシンセパラメータ要求
float CSuikaMain::getParameter(VstInt32 index) {
    return 0.f;
}

// **** パラメータ名要求
void CSuikaMain::getParameterName(VstInt32 index, char *text) {
    vst_strncpy(text, "PmNSuika", kVstMaxParamStrLen);
}

// **** パラメータ値対応テキスト要求
void CSuikaMain::getParameterDisplay(VstInt32 index, char *text) {
    vst_strncpy(text, "PmDSuika", kVstMaxParamStrLen);
}

// **** プログラム名要求
bool CSuikaMain::getProgramNameIndexed(VstInt32 category, VstInt32 index, char *name) {
    if (index < 0 || index >= PROGRAM_NUM) return false;
    vst_strncpy(name, "PgNISuika", kVstMaxProgNameLen);
    return true;
}

// **** カレントプログラム名要求
void CSuikaMain::getProgramName(char *name) {
    vst_strncpy(name, "PgNCSuika", kVstMaxProgNameLen);
}

// **** カレントプログラム変更
void CSuikaMain::setProgramName(char *name) {
}

// **** プログラム変更
void CSuikaMain::setProgram(VstInt32 program) {
}

// **** パッチ情報要求
VstInt32 CSuikaMain::getChunk(void **data, bool isPreset) {
    return 0;
}

// **** パッチ情報設定要求
VstInt32 CSuikaMain::setChunk(void *data, VstInt32 byteSize, bool isPreset) {
    return 1;
}


