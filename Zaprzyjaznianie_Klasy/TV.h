#pragma once
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
};

class Remote
{
private:
	int mode;
public:
	Remote(int m = Tv::TV) :mode(m) {}
	bool volup(Tv & t) { return t.volup(); }
	bool voldown(Tv& t) { return t.voldown(); }
	void onoff(Tv& t) { return t.onoff(); }
	void chanup(Tv& t) { return t.chanup(); }
	void chandonw(Tv& t) { return t.chandown(); }
	void set_chan(Tv& t, int c) { t.channel = c; }
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv & t) { t.set_input(); }
};

