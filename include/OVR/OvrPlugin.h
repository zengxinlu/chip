#pragma once

#ifndef _OVR_PLUGIN_OPTIX_
#define _OVR_PLUGIN_OPTIX_

#include "OVR_CAPI_GL.h"
//#include "Extras/OVR_Math.h"

struct TextureBuffer;
struct DepthBuffer;

class OvrPluginGL
{
public:
	ovrSession session;
	ovrGraphicsLuid luid;
	ovrHmdDesc hmdDesc;
	TextureBuffer * eyeRenderTexture[2];
	DepthBuffer * eyeDepthBuffer[2];
	ovrMirrorTexture mirrorTexture;
	unsigned int mirrorFBO;
	ovrEyeRenderDesc eyeRenderDesc[2];
	ovrPosef EyeRenderPose[2];
	ovrVector3f HmdToEyeOffset[2];
	double sensorSampleTime;
	float view[16];
	float proj[16];
	bool shouldQuit;
	bool isVisible;
	ovrSizei windowSize;
	long long frameIndex;

public:
	bool Init(int winw, int winh);
	bool BeforeRender();
	bool StartRender(int eye);
	bool PseudoRender(int eye);
	bool EndRender(int eye);
	bool AfterRender();
	bool Shutdown();
};

#endif // !_OVR_PLUGIN_OPTIX_
