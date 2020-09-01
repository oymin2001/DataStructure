#ifndef EVENT_H
#define EVENT_H
#include<iostream>
#include<string>
using namespace std;

enum EventStatus { GENERATED,ENQUEUED,PROCESSED,UNDEFINED};

class Event
{
	friend ostream& operator << (ostream& fout, const Event& e);
public:
	Event();
	Event(int event_no, int event_pri, int evtGenAddr);
	void printEvent();
	void setEventHandlerAddr(int evtHandlerAddr) { event_handler_addr = evtHandlerAddr; }
	void setEventGenAddr(int genAddr) { event_gen_addr = genAddr; }
	void setEventNo(int evtNo) { event_no = evtNo; }
	void setEventPri(int pri) { event_pri = pri; }
	void setEventStatus(EventStatus evtStatus) { eventStatus= evtStatus; }
	int getEventPri() { return event_pri; }
	int getEventNo() { return event_no; }
	bool operator>(Event& e) { return (event_pri > e.event_pri); }
	bool operator<(Event& e) { return (event_pri < e.event_pri); }

private:
	int event_no;
	int event_gen_addr;
	int event_handler_addr;
	int event_pri;
	EventStatus eventStatus;
};

Event::Event()
{

}
Event::Event(int event_no, int event_pri, int evtGenAddr)
{
	event_no = event_no;
	event_gen_addr = evtGenAddr;
	event_handler_addr = -1;
	event_pri = event_pri;
	eventStatus = GENERATED;
}

void Event::printEvent()
{
	printf("Evt(pri:%2d,gen:%2d,no:%3d) ", event_pri, event_gen_addr, event_no);
}

ostream& operator << (ostream& fout, const Event& evt)
{
	cout << "Evt( pri:" << evt.event_pri << ", gen:" << evt.event_gen_addr;
	cout << ", no:" << evt.event_no << '\n';
	
	return fout;
}


#endif // !EVENT_H

#pragma once
