#pragma once

#include "defines.h"

#include "libs/glm/glm.hpp"
#include "libs/glm/gtc/matrix_transform.hpp"

class Camera {
public:
	Camera(float fov, float width, float height) {
		procjection = glm::perspective(fov / 2.0F, width / height, .1F, 1000.0F);
		view        = glm::mat4(1.0F);
		position    = glm::vec3(0.0F);
		update();
	}

	virtual void update() {
		viewProj = procjection * view;
	}

	virtual void Translate(glm::vec3 v) {
		position += v;
		view = glm::translate(view, v * -1.0F);
	}

	glm::vec3 GetPosition() {
		return position;
	}

	glm::mat4 GetProcjection() {
		return procjection;
	}

	glm::mat4 GetView() {
		return view;
	}

	glm::mat4 GetViewProj() {
		return viewProj;
	}

protected:
	glm::vec3 position {};
	glm::mat4 procjection {};
	glm::mat4 view {};
	glm::mat4 viewProj {};
};
