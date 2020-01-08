#pragma once
#include <iostream>
class Tv;
class Remote
{
	friend class Tv;
private:
	int mode;
public:
	enum { OFF, ON };
	enum { MINVAL, MAXVAL = 20 };
	enum { ANTENNA, CABLE };
	enum { TV, DVD };
	Remote(int m = TV) :mode(m) {}
	bool volup(Tv& t);
	bool voldown(Tv& t);
	void onoff(Tv& t);
	void chanup(Tv& t);
	void chandonw(Tv& t);
	void set_chan(Tv& t, int c);
	void set_mode(Tv& t);
	void set_input(Tv& t);
};

class Tv
{
	friend class Remote;
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
public:
	enum { OFF, ON };
	enum { MINVAL, MAXVAL = 20 };
	enum { ANTENNA, CABLE };
	enum { TV, DVD };
	Tv(int s = OFF, int mc = 125) :state(s), volume(5), maxchannel(mc), channel(2), mode(CABLE), input(TV) {};
	void onoff() { state = (state == ON ? OFF : ON); }
	bool ison()const { return state == ON; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == ANTENNA ? CABLE : ANTENNA); }
	void set_input() { input = (input == TV ? DVD : TV); }
	void settings() const;
	void buzz(Remote& r);
};


inline bool Remote::volup(Tv& t) { return t.volup(); }
inline bool Remote::voldown(Tv& t) { return t.voldown(); }
inline void Remote::onoff(Tv& t) { return t.onoff(); }
inline void Remote::chanup(Tv& t) { return t.chanup(); }
inline void Remote::chandonw(Tv& t) { return t.chandown(); }
inline void Remote::set_chan(Tv& t, int c) { t.channel = c; }
inline void Remote::set_mode(Tv& t) { t.set_mode(); }
inline void Remote::set_input(Tv& t) { t.set_input(); }
inline void Tv::buzz(Remote& r) { std::cout << (r.mode == ANTENNA ? "Antena" : "Kabel"); }
