#pragma once
#include "OpenGLWidget.h"

#include <Cameras/phc.h>
#include <OpenglWrappers/DemoMeshes/BlinnPhongMesh.h>

class LeftWindow : public OpenGLWidget{
	redips::PhC *m_phc = new redips::PhC(45, 1.0f, 0.1f, 10000);
	redips::BlinnPhongMesh* m_mesh = nullptr;
public:
	LeftWindow(){}
	~LeftWindow(){}
	bool Initialize(){
		m_mesh = new redips::BlinnPhongMesh(new redips::Triangles("E:/Documents/models/a世界著名建筑/Effier/new_iffier.obj"));
		auto heart = m_mesh->model_ptr()->aabb_R().heart();
		m_phc->lookAt(heart + redips::float3(0, 0, 500), heart, redips::float3(0, 1, 0));
		return true;
	}
	void RenderScene(){
		m_mesh->uniformFloat3("lightColor", redips::float3(1, 1, 1));
		m_mesh->uniformFloat3("lightPos", m_phc->pos());
		m_mesh->uniformFloat3("cameraPos", m_phc->pos());
		m_mesh->uniformMat44f("model", redips::Mat44f::eye().ptr());
		m_mesh->uniformMat44f("projection", m_phc->glProjection().ptr());
		m_mesh->uniformMat44f("view", m_phc->glView().ptr());
		m_mesh->draw();
	}
};