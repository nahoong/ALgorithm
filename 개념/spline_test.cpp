
#include<iostream>
#include<vector>
#include"spline.h"
using namespace std;

#pragma warning(disable:4996)

struct MPos {
	double compensation;
	double mandrel;
	double conveyor;
	MPos(double Compensation, double Mandrel, double Conveyor = 0) : compensation(Compensation), mandrel(Mandrel), conveyor(Conveyor) {}
};

int main() {

	///////////////////////모터 포지션 셋팅///////////////////
	//PARAM_MPOS.m_motorPos -> m_motorPos

	vector<MPos> m_motorPos;

	FILE * stream = freopen("spline_test.txt", "r", stdin);
	double a, b, c;
	while (!feof(stream)) {
		scanf("%lf\t%lf\t%lf", &a, &b, &c);
		m_motorPos.push_back(MPos(a, b, c));
	}
	fclose(stdout);


	/////////////////////// 보간을 만들 x축 설정 linear(x) 1,2,3,,,361////
	vector<double> x;
	vector<double> y_compen;
	vector<double> y_mandrel;
	vector<double> y_conveyor;

	for (int i = 0; i < int(m_motorPos.size()); i++) {
		x.push_back(double(i));
		y_compen.push_back(m_motorPos[i].compensation);
		y_mandrel.push_back(m_motorPos[i].mandrel);
		y_conveyor.push_back(m_motorPos[i].conveyor);
	}


	tk::spline s_compensation, s_mandrel, s_conveyor;
	s_compensation.set_points(x, y_compen);
	s_mandrel.set_points(x, y_mandrel);
	s_conveyor.set_points(x, y_conveyor);

	int acc = 30;	//T	//assert(acc%2==0)

	int size = m_motorPos.size();
	double new_pos=0;

	vector<double> pos_com_new(size);
	vector<double> pos_man_new(size);
	vector<double> pos_con_new(size);
	vector<bool> visit(size, 0);

	vector<double> time_v(size, 0);

	freopen("spline_test_output.txt", "w", stdout);
	//because 360 + 1
	for (int i = 0; i < acc / 2; i++) {
	//assert(size>acc)
		new_pos += double(i) / acc;
		pos_com_new[i] = s_compensation(new_pos);
		pos_com_new[size - 1 - i] = s_compensation(double(size)-1 - new_pos);
		
		visit[i] = 1;
		visit[size - 1 - i] = 1;

		time_v[i] = new_pos;
		time_v[size - 1 - i] = double(size) - 1 - new_pos;

	}
	int count = 0;
	for (int i = acc/2; i < size-acc/2; i++) {
		double add_time = (double(size) - 2 * new_pos) / (size - acc -1 );
		count++;
		double d = new_pos + count * add_time;
		pos_com_new[i] = s_compensation(d);
		time_v[i] = d;
	}

	for (int i = 0; i < size; i++) {
		cout << time_v[i] << "\t" << pos_com_new[i] << endl;
	}
		/*
		SetTaskProgress((double)index / PARAM_MPOS.m_motorPos.size());
		STAGE.SendCommand("P%d=%f P%d=%f P%d=%f P%d=%f",
			2000 + index, PARAM_MPOS.m_motorPos[index].compensation,
			3000 + index, PARAM_MPOS.m_motorPos[index].mandrel,
			4000 + index, PARAM_MPOS.m_motorPos[index].conveyor,
			5000 + index, posA
			);
		*/
		//cout << new_pos << "\t" << s_compensation(new_pos) << "\t" << s_mandrel(new_pos) << "\t" << s_conveyor(new_pos) << endl;


	fclose(stdout);

	freopen("CON", "w", stdout);
	cout << m_motorPos.size() << "완료" << endl;
	fclose(stdout);
}