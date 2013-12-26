/*
 * RenderUtil.h
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#ifndef RENDERUTIL_H_
#define RENDERUTIL_H_

namespace Z3D_Base {

class RenderUtil {
public:
	RenderUtil();
	virtual ~RenderUtil();

	static void clearScreen();
	static void initGraphics();

	static char* getOpenGLVersion();
};

} /* namespace Z3D_Base */

#endif /* RENDERUTIL_H_ */
