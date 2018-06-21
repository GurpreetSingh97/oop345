#include <iostream>
#include <string>
#include "Notifications.h"
#include "Message.h"

using namespace std;

namespace w5 {
	Notifications::Notifications() {
		m_notifaications.clear();
	}
	Notifications::Notifications(const Notifications& obj) {
		m_notifaications = obj.m_notifaications;
	}

	Notifications& Notifications::operator=(const Notifications& obj) {
		if (this != &obj) {
			m_notifaications.clear();
			m_notifaications = obj.m_notifaications;
		}
		return *this;
	}

	Notifications::Notifications(Notifications&& obj) {
		m_notifaications = obj.m_notifaications;
		obj.m_notifaications.clear();
	}

	Notifications&& Notifications::operator==(Notifications&& obj) {
		if (this != &obj) {
			m_notifaications.clear();
			m_notifaications = move(obj.m_notifaications);
			obj.m_notifaications.clear();
		}
		return move(*this);
	}

	Notifications::~Notifications() {
		m_notifaications.clear();
	}

	void Notifications::operator+=(const Message& msg) {
		m_notifaications.push_back(msg);
	}

	void Notifications::display(std::ostream& os) const {
		for (auto i = m_notifaications.begin(); i != m_notifaications.end(); i++) {
			i->display(os);

			cout << endl;
		}
	}

}