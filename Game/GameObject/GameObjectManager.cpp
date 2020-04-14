#include "pch.h"

#include "GameObjectManager.h"

#include "IGameObject.h"




IGameObjectManager::IGameObjectManager()
	: m_objects()
	, m_objectQueue()
	,m_drawPrio(0)
{
}



IGameObjectManager::~IGameObjectManager()
{
}



void IGameObjectManager::Update(const DX::StepTimer& timer)
{
	DestroyObjects();


	if (!m_objectQueue.empty())
	{
		AcceptObjects();
	}


	UpdateObjects(timer);
}



void IGameObjectManager::Render(const DX::StepTimer& timer)
{
	std::list<IGameObject*> pObjects;
	IGameObjectList::iterator it = m_objects.begin();
	IGameObjectList::iterator end = m_objects.end();
	while (it != end)
	{
		pObjects.push_back((*it).get());
		++it;
	}
	pObjects.sort([](const IGameObject* a, const IGameObject* b) {
		return a->GetDrawPrio() > b->GetDrawPrio();
	});
	for (IGameObject* object : pObjects)
	{
		object->Render(timer);
	}
}



void IGameObjectManager::Add(IGameObjectPtr&& object)
{
	m_objectQueue.push_back(std::move(object));
}



void IGameObjectManager::UpdateObjects(const DX::StepTimer& timer)
{
	// ภ1 ออforถ
	for (IGameObjectPtr& object : m_objects)
	{
		object->Update(timer);
	}


	// ภ2 Ce[^
	//IGameObjectList::iterator it  = m_objects.begin();
	//IGameObjectList::iterator end = m_objects.end();
	//while (it != end)
	//{
	//	(*it)->Update(elapsedTime);
	//	++it;
	//}


	// ภ3 _ฎ
	//std::for_each(
	//	m_objects.begin(),
	//	m_objects.end(),
	//	[&](IGameObjectPtr& object) { object->Update(elapsedTime); }
	//);
}



void IGameObjectManager::AcceptObjects()
{
	// ภ1 ออforถ
	//for (IGameObjectPtr& object : m_objectQueue)
	//{
	//	m_objects.push_back(std::move(object));
	//}
	//m_objectQueue.clear();


	// ภ2 Ce[^
	//IGameObjectList::iterator it  = m_objectQueue.begin();
	//IGameObjectList::iterator end = m_objectQueue.end();
	//while (it != end)
	//{
	//	m_objects.push_back(std::move(*it));
	//	++it;
	//}
	//m_objectQueue.clear();


	// ภ3 vfฬฺฎ
	m_objects.splice(m_objects.end(), m_objectQueue);
}



void IGameObjectManager::DestroyObjects()
{
	// ภ1 Ce[^
	//IGameObjectList::iterator it  = m_objects.begin();
	//while (it != m_objects.end())
	//{
	//	if ((*it)->IsInvalid())
	//	{
	//		it = m_objects.erase(it);
	//	}
	//	else
	//	{
	//		++it;
	//	}
	//}


	// ภ2 ๐๊vท้Sฤฬvf๐ํ
	m_objects.remove_if(std::mem_fn(&IGameObject::IsInvalid));


	// ภ3 _ฎ
	//m_objects.remove_if([](const IGameObjectPtr& object) { return object->IsInvalid(); });
}
