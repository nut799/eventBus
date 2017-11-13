#pragma once

#include <vector>
#include <list>

//namespace bus {
	struct BaseEvent
	{
		virtual ~BaseEvent() {}
	protected:
		static size_t getNextType();
	};

	/*move to cpp for link error.
	size_t BaseEvent::getNextType()
	{
		static size_t type_count = 0;
		return type_count++;
	}
	*/

	template <typename EventType>
	struct EV : BaseEvent
	{
		static size_t type()
		{
			static size_t t_type = BaseEvent::getNextType();
			return t_type;
		}
	};

	//template<class EventType>
	class BaseEventHandler
	{
	public:
		virtual ~BaseEventHandler() {};
		virtual void invoke(BaseEvent* baseEvent) = 0;
	};


	template<class EventType, class T, class F>
	class EventHandler : public BaseEventHandler
	{
	public:
		using memberf_pointer = void(T::*)(EventType*);
		EventHandler(T* t, F m) : mObj(t), mFunPointer(m)
		{

		}

		bool compare(T* obj, F fun)
		{
			return obj == mObj && mFunPointer == fun;
		}

		void invoke(BaseEvent* baseEvent)
		{
			if (!baseEvent)
				return;
			EventType* event = dynamic_cast<EventType*>(baseEvent);//!
			if (event)
			{
				(mObj->*mFunPointer)(event);
			}
		}
	private:
		T* mObj;
		memberf_pointer mFunPointer;
	};


	class EventBus
	{
	private:
		static EventBus* Instance;
		std::vector<std::list<BaseEventHandler*>> m_subscribers;
	public:
		template<typename EventType, typename T, typename F>
		void subscribe(T* obj, F method)
		{
			size_t type = EV<EventType>::type();
			if (type >= m_subscribers.size())
				m_subscribers.resize(type + 1);

			//donot check the dumplicate,for efficiency
			BaseEventHandler* e = new EventHandler<EventType, T, F>(obj, method);
			m_subscribers[type].push_back(e);
		}

		template<typename EventType, typename T, typename F>
		void unSubcribe(T* observer, F fun)
		{
			//std::cout << (" unSubcribe call") << std::endl;
			size_t type = EV<EventType>::type();
			if (type >= m_subscribers.size())
				m_subscribers.resize(type + 1);
			auto& list = m_subscribers[type];
			for (auto it = list.begin(); it != list.end();)
			{
				BaseEventHandler* base = *it;
				if (base == nullptr)
					continue;

				//change dynamic_cast to static_cast?
				EventHandler<EventType, T, F>* handler = dynamic_cast<EventHandler<EventType, T, F>*>(base);
				if (handler && handler->compare(observer, fun))
				{
					//std::cout << (" unSubcribe remove") << std::endl;
					delete base;
					base = nullptr;
					//remove from list
					it = list.erase(it);
				}
				else
				{
					it++;
				}
			}
		}

		template<typename EventType>
		void emit(EventType* event)
		{
			size_t type = EV<EventType>::type();
			if (type >= m_subscribers.size())
				m_subscribers.resize(type + 1);
			auto& list = m_subscribers[type];
			for (auto it = list.begin(); it != list.end(); it++)
			{
				BaseEventHandler* base = *it;
				//BaseEventHandler<EventType>* base = static_cast<BaseEventHandler<EventType>*>(*it);
				if (base == nullptr)
					continue;
				base->invoke(event);
			}
		}

	public:
		static EventBus* getInstance();

		static void delInstance();
	};

 

//}//namespace eventbus

