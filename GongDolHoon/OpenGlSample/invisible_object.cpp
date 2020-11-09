#include "invisible_object.h"

namespace object {
	InvisibleObject::InvisibleObject(LoaderParams* p_param)
		:InterfaceObject(p_param), GongDolHoonBehaviour()
	{
	}

	void InvisibleObject::Start()
	{

	}

	// Invisible Object doesn't need Physics Update.
	void InvisibleObject::FixedUpdate() {}

	void InvisibleObject::Update()
	{
	}

	// Invisible Object doesn't need Render Update.
	void InvisibleObject::RenderObject() {}

	void InvisibleObject::Destroy()
	{

	}

}	// namespace object
