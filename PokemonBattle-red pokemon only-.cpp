#include <iostream>
#include <string>
#include <regex>
#include<vector>
#include<fstream>
#include<stdio.h>
#include<random>

#define ESC 0x1B													//�G�X�P�[�v�V�[�P���X�@����
using namespace std;

class POKEMON {
	string name;													//���O
	int H = 0, A = 0, B = 0, C = 0, D = 0, S = 0;					//������傭,��������,�ڂ�����,�Ƃ�����,�Ƃ��ڂ�,���΂₳
	int w1 = 0, w2 = 0, w3 = 0, w4 = 0;								//�Z1,2,3,4,
	int t1 = 0, t2 = 0;												//�^�C�v1,2

public:
	void setName(const string& newName) { name = newName; }					//���O�ǂݍ��ݗp�A�N�Z�b�T
	string getName() { return name; }										//���O�����p�A�N�Z�b�T

	void setH(int newH) { H = newH; }								//�̗͓ǂݍ��ݗp�A�N�Z�b�T
	int getH() { return H; }										//�̗͌����p�A�N�Z�b�T
	void setA(int newA) { A = newA; }								//���������ǂݍ��ݗp�A�N�Z�b�T
	int getA() { return A; }										//�������������p�A�N�Z�b�T
	void setB(int newB) { B = newB; }								//�ڂ�����ǂݍ��ݗp�A�N�Z�b�T
	int getB() { return B; }										//�ڂ����匟���p�A�N�Z�b�T
	void setC(int newC) { C = newC; }								//�Ƃ������ǂݍ��ݗp�A�N�Z�b�T
	int getC() { return C; }										//�Ƃ����������p�A�N�Z�b�T
	void setD(int newD) { D = newD; }								//�Ƃ��ڂ��ǂݍ��ݗp�A�N�Z�b�T
	int getD() { return D; }										//�Ƃ��ڂ������p�A�N�Z�b�T
	void setS(int newS) { S = newS; }								//���΂₳�ǂݍ��ݗp�A�N�Z�b�T
	int getS() { return S; }										//���΂₳�����p�A�N�Z�b�T

	void setW1(int newW1) { w1 = newW1; }								//�Z1	�ǂݍ��ݗp�A�N�Z�b�T
	int getW1() { return w1; }											//�Z1	�����p�A�N�Z�b�T
	void setW2(int newW2) { w2 = newW2; }								//�Z2	�ǂݍ��ݗp�A�N�Z�b�T
	int getW2() { return w2; }											//�Z2	�����p�A�N�Z�b�T	
	void setW3(int newW3) { w3 = newW3; }								//�Z3	�ǂݍ��ݗp�A�N�Z�b�T
	int getW3() { return w3; }											//�Z3	�����p�A�N�Z�b�T	
	void setW4(int newW4) { w4 = newW4; }								//�Z4	�ǂݍ��ݗp�A�N�Z�b�T
	int getW4() { return w4; }											//�Z4	�����p�A�N�Z�b�T

	void setT1(int newT1) { t1 = newT1; }								//�^�C�v�P	�ǂݍ��ݗp�A�N�Z�b�T
	int getT1() { return t1; }											//�^�C�v�P	�����p�A�N�Z�b�T
	void setT2(int newT2) { t2 = newT2; }								//�^�C�v�Q	�ǂݍ��ݗp�A�N�Z�b�T
	int getT2() { return t2; }											//�^�C�v�Q	�����p�A�N�Z�b�T

};


class WAZA {
	string wazaname;													//�Z��
	int type;															//�Z�̃^�C�v
	string bunnrui;														//�Z�̕���
	int i = 0, m = 0;													//�Z�̈З�,������
public:
	void setWAZA(const string& newWAZA) { wazaname = newWAZA; }			//�Z��		�ǂݍ��ݗp�A�N�Z�b�T
	string getWAZA() { return wazaname; }								//�Z��		�����p�A�N�Z�b�T

	void setTYPE(int newTYPE) { type = newTYPE; }						//�Z�^�C�v	�ǂݍ��ݗp�A�N�Z�b�T
	int getTYPE() { return type; }										//�Z�^�C�v	�����p�A�N�Z�b�T

	void setBU(const string& newBU) { bunnrui = newBU; }				//�Z����	�ǂݍ��ݗp�A�N�Z�b�T
	string getBU() { return bunnrui; }									//�Z����	�����p�A�N�Z�b�T

	void setI(int newI) { i = newI; }									//�Z�З�	�ǂݍ��ݗp�A�N�Z�b�T
	int getI() { return i; }											//�Z�З�	�����p�A�N�Z�b�T
	void setM(int newM) { m = newM; }									//�Z������	�ǂݍ��ݗp�A�N�Z�b�T
	int getM() { return m; }											//�Z������	�����p�A�N�Z�b�T

};


vector<POKEMON> vec;												//POKEMON��vector�ɐݒ�
vector<WAZA>vec2;													//WAZA��vector�ɐݒ�
vector<string>vec3;													//�^�C�v��vector�ɐݒ�


ifstream infile1("POKEMONZUKAN.txt");								//����t�@�C���̓ǂݍ���
ifstream infile2("WAZAZUKAN.txt");
ifstream infile3("TAIPU.txt");
string line;														//�s�𐔂��邽�߂̕ϐ�
regex rx1(R"(\s)");													//������̐��K��

void Class1() {

	int PNUM = 0;														//�|�P�����ւ�1���I�Ȕԍ��t��

	while (getline(infile1, line)) {										//�Ō�̍s�܂ŒT��
		sregex_token_iterator it1(line.begin(), line.end(), rx1, -1);		//��������

		string NAMAE = *it1++;											//���ɖ��O������

		int tairyoku = stoi(*it1++);
		int kougeki = stoi(*it1++);
		int bougyo = stoi(*it1++);
		int tokukou = stoi(*it1++);
		int tokubou = stoi(*it1++);
		int subayasa = stoi(*it1++);

		int waza1 = stoi(*it1++);
		int waza2 = stoi(*it1++);
		int waza3 = stoi(*it1++);
		int waza4 = stoi(*it1++);

		int taipu1 = stoi(*it1++);
		int taipu2 = stoi(*it1);

		vec.emplace_back();												//�v�f�̊m��
		vec[PNUM].setName(NAMAE);										//���O�̊i�[

		vec[PNUM].setH(tairyoku);										//������傭�̊i�[
		vec[PNUM].setA(kougeki);										//���������̊i�[
		vec[PNUM].setB(bougyo);											//�ڂ�����̊i�[
		vec[PNUM].setC(tokukou);										//�Ƃ������̊i�[
		vec[PNUM].setD(tokubou);										//�Ƃ��ڂ��̊i�[
		vec[PNUM].setS(subayasa);										//���΂₳�̊i�[

		vec[PNUM].setW1(waza1);										//�Z�P�̊i�[
		vec[PNUM].setW2(waza2);										//�Z�Q�̊i�[
		vec[PNUM].setW3(waza3);										//�Z�R�̊i�[
		vec[PNUM].setW4(waza4);										//�Z�S�̊i�[

		vec[PNUM].setT1(taipu1);										//�^�C�v�P�̊i�[
		vec[PNUM].setT2(taipu2);										//�^�C�v�Q�̊i�[

		PNUM++;													//���̃|�P�����ւ̈ڍs

	}
}

void Class2() {
	int WNUM = 0;

	while (getline(infile2, line)) {										//�Ō�̍s�܂ŒT��
		sregex_token_iterator it2(line.begin(), line.end(), rx1, -1);		//��������

		string WNAMAE = *it2++;												//�Z��			������
		int WT = stoi(*it2++);												//�Z�^�C�v		������
		string WB = *it2++;													//�Z����		������
		int WI = stoi(*it2++);												//�Z�̈З�		������
		int WM = stoi(*it2++);												//�Z�̖�����	������

		vec2.emplace_back();
		vec2[WNUM].setWAZA(WNAMAE);											//�Z��			�̊i�[
		vec2[WNUM].setTYPE(WT);												//�Z�^�C�v		�̊i�[
		vec2[WNUM].setBU(WB);												//�Z����		�̊i�[
		vec2[WNUM].setI(WI);												//�Z�̈З�		�̊i�[
		vec2[WNUM].setM(WM);												//�Z�̖�����	�̊i�[

		WNUM++;																//���̋Z�ւ̈ڍs
	}
}

void VEC() {
	while (getline(infile3, line)) {										//�Ō�̍s�܂ŒT��
		sregex_token_iterator it3(line.begin(), line.end(), rx1, -1);		//��������
		for (int i = 0;i < 12;) {
			string Type = *it3++;												//�^�C�v		������

			vec3.emplace_back();
			vec3[i] = Type;														//�^�C�v		�̊i�[
			i++;																//���̃^�C�v�ւ̈ڍs
		}
	}

}



uniform_int_distribution<unsigned>dist1(0, 3);				//�ΐ푊��̃R�}���h�I��p��������	����1
random_device engine;										//�ΐ푊��̃R�}���h�I��p��������	����2
uniform_real_distribution<double>dist2(0.0, 1.0);			//�}���m���p��������	����


int Damage(int x, int y, int z, double d) {				//�Z��ł�,�Z���󂯂鑤,�R�}���h���͓��e,�}���m��

	int I = 0;								//�Z��	�p�ϐ�
	int D = 0;								//�_���[�W�p�ϐ�
	string S;								//�Z���ޔ��ʗp�ϐ�
	if (z == 0) {							//�Z1��I�������ꍇ
		I = vec2[vec[x].getW1()].getI();
		S = vec2[vec[x].getW1()].getBU();
	}
	else if (z == 1) {						//�Z2��I�������ꍇ
		I = vec2[vec[x].getW2()].getI();
		S = vec2[vec[x].getW2()].getBU();
	}
	else if (z == 2) {						//�Z3��I�������ꍇ
		I = vec2[vec[x].getW3()].getI();
		S = vec2[vec[x].getW3()].getBU();
	}
	else if (z == 3) {						//�Z4��I�������ꍇ
		I = vec2[vec[x].getW4()].getI();
		S = vec2[vec[x].getW4()].getBU();
	}

	double M = 1.0;
	if (d > 0.5)M = 1.75;																	//50%�̊m���Ń_���[�W��1.75�{


	if (stoi(S) == 1)		 D = ((22 * I * vec[x].getA() / vec[y].getB()) / 50 * M / 1);		//�����U���̂Ƃ�

	else if (stoi(S) == 2)	 D = ((22 * I * vec[x].getC() / vec[y].getD()) / 50 * M / 1);	//����U���̂Ƃ�
	return D;
}




void Draw(int a, int x2, int y2) {											//�����|�P�����`��֐�

	if (a == 0) {
		printf("%c[31m", ESC);
		printf("%c[47m", ESC);
		printf("%c[%d;%dH������", ESC, y2, x2);
		printf("%c[%d;%dH���@�@��", ESC, (y2 + 1), x2);
		printf("%c[%d;%dH������", ESC, y2 + 2, x2);
		printf("%c[%d;%dH���@ ��", ESC, y2 + 3, x2);
		printf("%c[%d;%dH���@�@��", ESC, y2 + 4, x2);
	}


	if (a == 1) {
		printf("%c[34m", ESC);
		printf("%c[47m", ESC);
		printf("%c[%d;%dH��    ��", ESC, y2, x2);
		printf("%c[%d;%dH��  ��", ESC, (y2 + 1), x2);
		printf("%c[%d;%dH����", ESC, y2 + 2, x2);
		printf("%c[%d;%dH���@��", ESC, y2 + 3, x2);
		printf("%c[%d;%dH���@  ��", ESC, y2 + 4, x2);
	}

	if (a == 2) {
		printf("%c[32m", ESC);
		printf("%c[47m", ESC);
		printf("%c[%d;%dH��������", ESC, y2, x2);
		printf("%c[%d;%dH���@�@�@", ESC, (y2 + 1), x2);
		printf("%c[%d;%dH������", ESC, y2 + 2, x2);
		printf("%c[%d;%dH��", ESC, y2 + 3, x2);
		printf("%c[%d;%dH��", ESC, y2 + 4, x2);
	}

	if (a == 3) {
		printf("%c[33m", ESC);
		printf("%c[47m", ESC);
		printf("%c[%d;%dH������", ESC, y2, x2);
		printf("%c[%d;%dH���@�@��", ESC, (y2 + 1), x2);
		printf("%c[%d;%dH������", ESC, y2 + 2, x2);
		printf("%c[%d;%dH��", ESC, y2 + 3, x2);
		printf("%c[%d;%dH��", ESC, y2 + 4, x2);
	}
}

void wait() {										//�ҋ@���Ԑ����p�֐�
	for (int i = 0;i < 500000000;++i) {}
}


void BattleWindow(int a, int b, int H1, int H2) {		//�o�g����ʕ`��p�֐�

	system("cls");						//��ʃN���A

	printf("%c[30m", ESC);
	printf("%c[47m", ESC);
	cout << endl << "  " << vec[b].getName() << endl << "�@�̗� : " << H2;
	for (int i = 0;i < 17;++i)cout << endl;

	cout << "                                                      " << vec[a].getName() << endl;
	cout << "                                                      " << "�̗� : " << H1 << endl << endl;

	int x1 = 50, y1 = 5;				//����|�P�����\���p���W�n
	int x2 = 10, y2 = 17;				//�����|�P�����\���p���W�n
	Draw(b, x1, y1);					//����|�P�����\��
	Draw(a, x2, y2);					//�����|�P�����\��


	printf("%c[30m", ESC);
	for (int i = 0;i < 3;++i)cout << endl;
	cout << vec[a].getName() << "�@�͂ǂ�����H\n";

	string B1 = "����", B2 = "����", B3 = "����", B4 = "����";		//�Z�^�C�v���ޏ����l

	if (stoi(vec2[vec[a].getW1()].getBU()) == 1)B1 = "����";
	if (stoi(vec2[vec[a].getW2()].getBU()) == 1)B2 = "����";
	if (stoi(vec2[vec[a].getW3()].getBU()) == 1)B3 = "����";
	if (stoi(vec2[vec[a].getW4()].getBU()) == 1)B4 = "����";



	cout << "0." << vec2[vec[a].getW1()].getWAZA() << "�@         �@�^�C�v : " << vec3[vec2[vec[a].getW1()].getTYPE()] << "�@�@���� : " << B1 << "�@�@�З� : " << vec2[vec[a].getW1()].getI() << "�@�@������ : " << vec2[vec[a].getW1()].getM() << endl
		<< "1." << vec2[vec[a].getW2()].getWAZA() << "�@         �@�^�C�v : " << vec3[vec2[vec[a].getW2()].getTYPE()] << "�@�@���� : " << B2 << "�@�@�З� : " << vec2[vec[a].getW2()].getI() << "�@�@������ : " << vec2[vec[a].getW2()].getM() << endl
		<< "2." << vec2[vec[a].getW3()].getWAZA() << "�@         �@�^�C�v : " << vec3[vec2[vec[a].getW3()].getTYPE()] << "�@�@���� : " << B3 << "�@�@�З� : " << vec2[vec[a].getW3()].getI() << "�@�@������ : " << vec2[vec[a].getW3()].getM() << endl
		<< "3." << vec2[vec[a].getW4()].getWAZA() << "�@         �@�^�C�v : " << vec3[vec2[vec[a].getW4()].getTYPE()] << "�@�@���� : " << B4 << "�@�@�З� : " << vec2[vec[a].getW4()].getI() << "�@�@������ : " << vec2[vec[a].getW4()].getM() << endl
		<< endl;


}




void VS(int a, int b) {							//�ΐ�i�s�p�֐�

	int H1 = vec[a].getH(), H2 = vec[b].getH();		//�e�|�P�����̗̑͂̐ݒ�
	int c = 0;							//�W�����͗p�ϐ�
	string C;
	double KA = 0.5;
	printf("%c[47m", ESC);



	while (1) {							//�ǂ��炩�̗̑͂�0�ȉ��ɂȂ�goto end�@�Ń��[�v�̊O�ɔ�΂Ȃ�����,���[�v���甲���o���Ȃ�
		BattleWindow(a, b, H1, H2);

		int Q = 0;							//0,1,2,3���o�p�ϐ�
		do {
			Q = 0;
			cout << "�I���������Z�̔ԍ��i0,1,2,3)����͂��Ă�������.���͌�Enter�Ŋm��ł��܂�\n";
			cin >> C;

			if (all_of(C.cbegin(), C.cend(), isdigit)) {										//10�i�����ǂ������m
				if (stoi(C) == 0 || stoi(C) == 1 || stoi(C) == 2 || stoi(C) == 3)Q = 1;			//0,1,2,3���ǂ������m
				else cout << "0,1,2,3�ȊO�̕��������͂���܂����I�I������x���͂���蒼���Ă�������\n";
			}
			else cout << "0,1,2,3�ȊO�̕��������͂���܂����I�I������x���͂���蒼���Ă�������\n";
		} while (Q == 0);						//0,1,2,3�ȊO�̓��͂ł̓��[�v����o���Ȃ�



		c = stoi(C);							//���͓��e��int�ɕϊ�
		int SE = dist1(engine);					//����|�P�����̋Z�I��,�����̎����Ă�4�̋Z����1�̋Z��I��(0,1,2,3�𐶐��j
		double d = 0;							//�}���m�������p�ϐ� ������


		if (vec[a].getS() >= vec[b].getS()) {						//�����|�P�����̂��΂₳������,�������͂��Ȃ����΂₳

			cout << endl << "�����I" << vec[a].getName() << "��";
			if (c == 0)cout << vec2[vec[a].getW1()].getWAZA();
			else if (c == 1)cout << vec2[vec[a].getW2()].getWAZA();
			else if (c == 2)cout << vec2[vec[a].getW3()].getWAZA();
			else if (c == 3)cout << vec2[vec[a].getW4()].getWAZA();
			cout << "!" << endl;
			wait();

			d = dist2(engine);						//�}���m������
			if (d > KA)cout << "�}���ɓ��������I�I�I�I�I�I" << endl;

			cout << "�����" << vec[b].getName() << "��" << Damage(a, b, c, d) << "�̃_���[�W���󂯂�!\n";
			wait();


			H2 = H2 - Damage(a, b, c, d);			//�_���[�W�v�Z��̗͂̔��f

			if (H2 < 0) {
				H2 = 0;
				BattleWindow(a, b, H1, H2);
				cout << "������" << vec[a].getName() << "�̏���!";
				goto end;
			}

			cout << "���ɑ����" << vec[b].getName() << "��";
			if (SE == 0)cout << vec2[vec[b].getW1()].getWAZA();
			else if (SE == 1)cout << vec2[vec[b].getW2()].getWAZA();
			else if (SE == 2)cout << vec2[vec[b].getW3()].getWAZA();
			else if (SE == 3)cout << vec2[vec[b].getW4()].getWAZA();
			cout << "!" << endl;
			wait();

			d = dist2(engine);						//�}���m������
			if (d > KA)cout << "�}���ɓ��������I�I�I�I�I�I" << endl;

			cout << "������" << vec[a].getName() << "��" << Damage(b, a, SE, d) << "�̃_���[�W���󂯂�!\n";
			wait();
			H1 = H1 - Damage(b, a, SE, d);			//�_���[�W�v�Z��̗͂̔��f
			if (H1 < 0) {
				H1 = 0;
				BattleWindow(a, b, H1, H2);
				cout << "�����Ă��܂���.....�����" << vec[b].getName() << "�̏���!";
				goto end;
			}
		}

		if (vec[a].getS() < vec[b].getS()) {				//����̃|�P�����̂��΂₳�̂ق��������ꍇ

			cout << "���΂₢�����" << vec[b].getName() << "��";
			if (SE == 0)cout << vec2[vec[b].getW1()].getWAZA();
			else if (SE == 1)cout << vec2[vec[b].getW2()].getWAZA();
			else if (SE == 2)cout << vec2[vec[b].getW3()].getWAZA();
			else if (SE == 3)cout << vec2[vec[b].getW4()].getWAZA();
			cout << "!" << endl;
			wait();

			d = dist2(engine);						//�}���m������
			if (d > KA)cout << "�}���ɓ��������I�I�I�I�I�I" << endl;

			cout << "������" << vec[a].getName() << "��" << Damage(b, a, SE, d) << "�̃_���[�W���󂯂�!\n";
			wait();

			H1 = H1 - Damage(b, a, SE, d);			//�_���[�W�v�Z��̗͂̔��f
			if (H1 < 0) {
				H1 = 0;
				BattleWindow(a, b, H1, H2);
				cout << "�����Ă��܂���.....�����" << vec[b].getName() << "�̏���!";
				goto end;
			}

			cout << endl << "����" << vec[a].getName() << "��";
			if (c == 0)cout << vec2[vec[a].getW1()].getWAZA();
			else if (c == 1)cout << vec2[vec[a].getW2()].getWAZA();
			else if (c == 2)cout << vec2[vec[a].getW3()].getWAZA();
			else if (c == 3)cout << vec2[vec[a].getW4()].getWAZA();
			cout << "!" << endl;
			wait();

			d = dist2(engine);						//�}���m������
			if (d > KA)cout << "�}���ɓ��������I�I�I�I�I�I" << endl;

			cout << "�����" << vec[b].getName() << "��" << Damage(a, b, c, d) << "�̃_���[�W���󂯂�!\n";
			wait();

			H2 = H2 - Damage(a, b, c, d);			//�_���[�W�v�Z��̗͂̔��f
			if (H2 < 0) {
				H2 = 0;
				BattleWindow(a, b, H1, H2);
				cout << "������" << vec[a].getName() << "�̏���!";
				goto end;
			}
		}
	}


end:
	cout << endl << endl;


}











int main() {
	Class1();
	Class2();
	VEC();

	string a, b;						//����,����|�P�����I��p�ϐ�
	int Q = 0;							//���̓G���[���o�p�ϐ�

	system("cls");						//��ʃN���A

	do {
		Q = 0;
		cout << "�����̎g�������|�P������ԍ��őI���,�ԍ��i0,1,2,3)����͂��Ă�������.���͌�Enter�Ŋm��ł��܂�\n";
		int p = 0;
		for (auto A1 : vec) {
			cout << p << "." << A1.getName() << "       \n";		//�e�|�P��������
			p++;
		}

		cin >> a;						//�����|�P�����I��
		if (all_of(a.cbegin(), a.cend(), isdigit)) {									//10�i�����ǂ������m
			if (stoi(a) == 0 || stoi(a) == 1 || stoi(a) == 2 || stoi(a) == 3)Q = 1;		//0,1,2,3���ǂ������m
			else cout << "0,1,2,3�ȊO�̕��������͂���܂����I�I������x���͂���蒼���Ă�������\n";
		}
		else cout << "0,1,2,3�ȊO�̕��������͂���܂����I�I������x���͂���蒼���Ă�������\n";
	} while (Q == 0);						//0,1,2,3�ȊO�̓��͂ł̓��[�v����o���Ȃ�


	cout << endl << "���Ȃ����I�񂾃|�P������" << vec[stoi(a)].getName() << "�ł�." << endl;

	do {
		Q = 0;
		cout << "���ɑ���̃|�P������I���,�ԍ��i0,1,2,3)����͂��Ă�������.���͌�Enter�Ŋm��ł��܂�\n";

		int p = 0;
		for (auto A1 : vec) {
			cout << p << "." << A1.getName() << "       \n";
			p++;
		}

		cin >> b;							//����|�P�����I��
		if (all_of(b.cbegin(), b.cend(), isdigit)) {										//10�i�����ǂ������m
			if (stoi(b) == 0 || stoi(b) == 1 || stoi(b) == 2 || stoi(b) == 3)Q = 1;			//0,1,2,3���ǂ������m
			else cout << "0,1,2,3�ȊO�̕��������͂���܂����I�I������x���͂���蒼���Ă�������\n";
		}
		else cout << "0,1,2,3�ȊO�̕��������͂���܂����I�I������x���͂���蒼���Ă�������\n";
	} while (Q == 0);						//0,1,2,3�ȊO�̓��͂ł̓��[�v����o���Ȃ�


	cout << endl << "����̃|�P������" << vec[stoi(b)].getName() << "�ł�.\n";
	cout << "�ΐ��ʂɉf��܂�.���X���҂���������";
	wait();																	//����|�P�����m�F�p�ҋ@���Ԑ���





	VS(stoi(a), stoi(b));													//�ΐ�J�n

}
