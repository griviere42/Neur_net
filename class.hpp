#ifndef CLASS_HPP_INCLUDED
#define CLASS_HPP_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>

const float learn_rate = 3.f;

class Neur
{
private:
    int m_nb_branchs;
    float *m_weight;
	float *m_weight_old;
    float sigmo(float val);
	float m_bias;
	
	
public:
	Neur();
    Neur(int nb_branchs);
	void setBranchs(int nb);
    float learning(float* input, float error_factor);
    float test(float *input);
	float get_weight(int i){
		if(i < m_nb_branchs)
			return m_weight_old[i];
		else
			return 0;
	};
};

class Net{
	
	private:
		Neur* input_layer;
		Neur* output_layer;
		int m_width;
		int m_nb_input;
	
	public:
		Net(int width, int nb_input);
		float learning(float m_expect, float *input);
		float test(float *input);
		void getState();
};

#endif // CLASS_HPP_INCLUDED
