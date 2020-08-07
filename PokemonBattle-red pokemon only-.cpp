#include <iostream>
#include <string>
#include <regex>
#include<vector>
#include<fstream>
#include<stdio.h>
#include<random>

#define ESC 0x1B									//エスケープシーケンス　準備
using namespace std;

class POKEMON {
	string name;									//名前
	int H = 0, A = 0, B = 0, C = 0, D = 0, S = 0;					//たいりょく,こうげき,ぼうぎょ,とくこう,とくぼう,すばやさ
	int w1 = 0, w2 = 0, w3 = 0, w4 = 0;						//技1,2,3,4,
	int t1 = 0, t2 = 0;								//タイプ1,2

public:
	void setName(const string& newName) { name = newName; }						//名前読み込み用アクセッサ
	string getName() { return name; }								//名前検索用アクセッサ

	void setH(int newH) { H = newH; }								//体力読み込み用アクセッサ
	int getH() { return H; }									//体力検索用アクセッサ
	void setA(int newA) { A = newA; }								//こうげき読み込み用アクセッサ
	int getA() { return A; }									//こうげき検索用アクセッサ
	void setB(int newB) { B = newB; }								//ぼうぎょ読み込み用アクセッサ
	int getB() { return B; }									//ぼうぎょ検索用アクセッサ
	void setC(int newC) { C = newC; }								//とくこう読み込み用アクセッサ
	int getC() { return C; }									//とくこう検索用アクセッサ
	void setD(int newD) { D = newD; }								//とくぼう読み込み用アクセッサ
	int getD() { return D; }									//とくぼう検索用アクセッサ
	void setS(int newS) { S = newS; }								//すばやさ読み込み用アクセッサ
	int getS() { return S; }									//すばやさ検索用アクセッサ

	void setW1(int newW1) { w1 = newW1; }								//技1	読み込み用アクセッサ
	int getW1() { return w1; }									//技1	検索用アクセッサ
	void setW2(int newW2) { w2 = newW2; }								//技2	読み込み用アクセッサ
	int getW2() { return w2; }									//技2	検索用アクセッサ	
	void setW3(int newW3) { w3 = newW3; }								//技3	読み込み用アクセッサ
	int getW3() { return w3; }									//技3	検索用アクセッサ	
	void setW4(int newW4) { w4 = newW4; }								//技4	読み込み用アクセッサ
	int getW4() { return w4; }									//技4	検索用アクセッサ

	void setT1(int newT1) { t1 = newT1; }								//タイプ１	読み込み用アクセッサ
	int getT1() { return t1; }									//タイプ１	検索用アクセッサ
	void setT2(int newT2) { t2 = newT2; }								//タイプ２	読み込み用アクセッサ
	int getT2() { return t2; }									//タイプ２	検索用アクセッサ

};


class WAZA {
	string wazaname;										//技名
	int type;											//技のタイプ
	string bunnrui;											//技の分類
	int i = 0, m = 0;										//技の威力,命中率
public:
	void setWAZA(const string& newWAZA) { wazaname = newWAZA; }			//技名		読み込み用アクセッサ
	string getWAZA() { return wazaname; }						//技名		検索用アクセッサ

	void setTYPE(int newTYPE) { type = newTYPE; }					//技タイプ	読み込み用アクセッサ
	int getTYPE() { return type; }							//技タイプ	検索用アクセッサ

	void setBU(const string& newBU) { bunnrui = newBU; }				//技分類	読み込み用アクセッサ
	string getBU() { return bunnrui; }						//技分類	検索用アクセッサ

	void setI(int newI) { i = newI; }						//技威力	読み込み用アクセッサ
	int getI() { return i; }							//技威力	検索用アクセッサ
	void setM(int newM) { m = newM; }						//技命中率	読み込み用アクセッサ
	int getM() { return m; }							//技命中率	検索用アクセッサ

};


vector<POKEMON> vec;									//POKEMONをvectorに設定
vector<WAZA>vec2;									//WAZAをvectorに設定
vector<string>vec3;									//タイプをvectorに設定


ifstream infile1("POKEMONZUKAN.txt");							//名簿ファイルの読み込み
ifstream infile2("WAZAZUKAN.txt");
ifstream infile3("TAIPU.txt");
string line;										//行を数えるための変数
regex rx1(R"(\s)");									//文字列の正規化

void Class1() {

	int PNUM = 0;									//ポケモンへの1次的な番号付け

	while (getline(infile1, line)) {						//最後の行まで探索
		sregex_token_iterator it1(line.begin(), line.end(), rx1, -1);		//検索条件

		string NAMAE = *it1++;							//次に名前を検索

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

		vec.emplace_back();											//要素の確保
		vec[PNUM].setName(NAMAE);										//名前の格納

		vec[PNUM].setH(tairyoku);										//たいりょくの格納
		vec[PNUM].setA(kougeki);										//こうげきの格納
		vec[PNUM].setB(bougyo);											//ぼうぎょの格納
		vec[PNUM].setC(tokukou);										//とくこうの格納
		vec[PNUM].setD(tokubou);										//とくぼうの格納
		vec[PNUM].setS(subayasa);										//すばやさの格納

		vec[PNUM].setW1(waza1);											//技１の格納
		vec[PNUM].setW2(waza2);											//技２の格納
		vec[PNUM].setW3(waza3);											//技３の格納
		vec[PNUM].setW4(waza4);											//技４の格納

		vec[PNUM].setT1(taipu1);										//タイプ１の格納
		vec[PNUM].setT2(taipu2);										//タイプ２の格納

		PNUM++;													//次のポケモンへの移行

	}
}

void Class2() {
	int WNUM = 0;

	while (getline(infile2, line)) {										//最後の行まで探索
		sregex_token_iterator it2(line.begin(), line.end(), rx1, -1);		//検索条件

		string WNAMAE = *it2++;											//技名		を検索
		int WT = stoi(*it2++);											//技タイプ		を検索
		string WB = *it2++;											//技分類		を検索
		int WI = stoi(*it2++);											//技の威力		を検索
		int WM = stoi(*it2++);											//技の命中率	を検索

		vec2.emplace_back();
		vec2[WNUM].setWAZA(WNAMAE);										//技名		の格納
		vec2[WNUM].setTYPE(WT);											//技タイプ		の格納
		vec2[WNUM].setBU(WB);											//技分類		の格納
		vec2[WNUM].setI(WI);											//技の威力		の格納
		vec2[WNUM].setM(WM);											//技の命中率	の格納

		WNUM++;													//次の技への移行
	}
}

void VEC() {
	while (getline(infile3, line)) {						//最後の行まで探索
		sregex_token_iterator it3(line.begin(), line.end(), rx1, -1);		//検索条件
		for (int i = 0;i < 12;) {
			string Type = *it3++;						//タイプ		を検索

			vec3.emplace_back();
			vec3[i] = Type;							//タイプ		の格納
			i++;								//次のタイプへの移行
		}
	}

}



uniform_int_distribution<unsigned>dist1(0, 3);				//対戦相手のコマンド選択用乱数生成	準備1
random_device engine;							//対戦相手のコマンド選択用乱数生成	準備2
uniform_real_distribution<double>dist2(0.0, 1.0);			//急所確率用乱数生成	準備


int Damage(int x, int y, int z, double d) {				//技を打つ側,技を受ける側,コマンド入力内容,急所確率

	int I = 0;							//技威	用変数
	int D = 0;							//ダメージ用変数
	string S;							//技分類判別用変数
	if (z == 0) {							//技1を選択した場合
		I = vec2[vec[x].getW1()].getI();
		S = vec2[vec[x].getW1()].getBU();
	}
	else if (z == 1) {						//技2を選択した場合
		I = vec2[vec[x].getW2()].getI();
		S = vec2[vec[x].getW2()].getBU();
	}
	else if (z == 2) {						//技3を選択した場合
		I = vec2[vec[x].getW3()].getI();
		S = vec2[vec[x].getW3()].getBU();
	}
	else if (z == 3) {						//技4を選択した場合
		I = vec2[vec[x].getW4()].getI();
		S = vec2[vec[x].getW4()].getBU();
	}

	double M = 1.0;
	if (d > 0.5)M = 1.75;											//50%の確率でダメージが1.75倍


	if (stoi(S) == 1)		 D = ((22 * I * vec[x].getA() / vec[y].getB()) / 50 * M / 1);		//物理攻撃のとき

	else if (stoi(S) == 2)	 D = ((22 * I * vec[x].getC() / vec[y].getD()) / 50 * M / 1);			//特殊攻撃のとき
	return D;
}




void Draw(int a, int x2, int y2) {				//ポケモン描画関数

	if (a == 0) {
		printf("%c[31m", ESC);
		printf("%c[47m", ESC);
		printf("%c[%d;%dH●●●", ESC, y2, x2);
		printf("%c[%d;%dH●　　●", ESC, (y2 + 1), x2);
		printf("%c[%d;%dH●●●", ESC, y2 + 2, x2);
		printf("%c[%d;%dH●　 ●", ESC, y2 + 3, x2);
		printf("%c[%d;%dH●　　●", ESC, y2 + 4, x2);
	}


	if (a == 1) {
		printf("%c[34m", ESC);
		printf("%c[47m", ESC);
		printf("%c[%d;%dH●    ●", ESC, y2, x2);
		printf("%c[%d;%dH●  ●", ESC, (y2 + 1), x2);
		printf("%c[%d;%dH●●", ESC, y2 + 2, x2);
		printf("%c[%d;%dH●　●", ESC, y2 + 3, x2);
		printf("%c[%d;%dH●　  ●", ESC, y2 + 4, x2);
	}

	if (a == 2) {
		printf("%c[32m", ESC);
		printf("%c[47m", ESC);
		printf("%c[%d;%dH●●●●", ESC, y2, x2);
		printf("%c[%d;%dH●　　　", ESC, (y2 + 1), x2);
		printf("%c[%d;%dH●●●", ESC, y2 + 2, x2);
		printf("%c[%d;%dH●", ESC, y2 + 3, x2);
		printf("%c[%d;%dH●", ESC, y2 + 4, x2);
	}

	if (a == 3) {
		printf("%c[33m", ESC);
		printf("%c[47m", ESC);
		printf("%c[%d;%dH●●●", ESC, y2, x2);
		printf("%c[%d;%dH●　　●", ESC, (y2 + 1), x2);
		printf("%c[%d;%dH●●●", ESC, y2 + 2, x2);
		printf("%c[%d;%dH●", ESC, y2 + 3, x2);
		printf("%c[%d;%dH●", ESC, y2 + 4, x2);
	}
}

void wait() {							//待機時間生成用関数
	for (int i = 0;i < 500000000;++i) {}
}


void BattleWindow(int a, int b, int H1, int H2) {		//バトル画面描画用関数

	system("cls");						//画面クリア

	printf("%c[30m", ESC);
	printf("%c[47m", ESC);
	cout << endl << "  " << vec[b].getName() << endl << "　体力 : " << H2;
	for (int i = 0;i < 17;++i)cout << endl;

	cout << "                                                      " << vec[a].getName() << endl;
	cout << "                                                      " << "体力 : " << H1 << endl << endl;

	int x1 = 50, y1 = 5;				//相手ポケモン表示用座標系
	int x2 = 10, y2 = 17;				//自分ポケモン表示用座標系
	Draw(b, x1, y1);					//相手ポケモン表示
	Draw(a, x2, y2);					//自分ポケモン表示


	printf("%c[30m", ESC);
	for (int i = 0;i < 3;++i)cout << endl;
	cout << vec[a].getName() << "　はどうする？\n";

	string B1 = "特殊", B2 = "特殊", B3 = "特殊", B4 = "特殊";		//技タイプ分類初期値

	if (stoi(vec2[vec[a].getW1()].getBU()) == 1)B1 = "物理";
	if (stoi(vec2[vec[a].getW2()].getBU()) == 1)B2 = "物理";
	if (stoi(vec2[vec[a].getW3()].getBU()) == 1)B3 = "物理";
	if (stoi(vec2[vec[a].getW4()].getBU()) == 1)B4 = "物理";



	cout << "0." << vec2[vec[a].getW1()].getWAZA() << "　         　タイプ : " << vec3[vec2[vec[a].getW1()].getTYPE()] << "　　分類 : " << B1 << "　　威力 : " << vec2[vec[a].getW1()].getI() << "　　命中率 : " << vec2[vec[a].getW1()].getM() << endl
		<< "1." << vec2[vec[a].getW2()].getWAZA() << "　         　タイプ : " << vec3[vec2[vec[a].getW2()].getTYPE()] << "　　分類 : " << B2 << "　　威力 : " << vec2[vec[a].getW2()].getI() << "　　命中率 : " << vec2[vec[a].getW2()].getM() << endl
		<< "2." << vec2[vec[a].getW3()].getWAZA() << "　         　タイプ : " << vec3[vec2[vec[a].getW3()].getTYPE()] << "　　分類 : " << B3 << "　　威力 : " << vec2[vec[a].getW3()].getI() << "　　命中率 : " << vec2[vec[a].getW3()].getM() << endl
		<< "3." << vec2[vec[a].getW4()].getWAZA() << "　         　タイプ : " << vec3[vec2[vec[a].getW4()].getTYPE()] << "　　分類 : " << B4 << "　　威力 : " << vec2[vec[a].getW4()].getI() << "　　命中率 : " << vec2[vec[a].getW4()].getM() << endl
		<< endl;


}




void VS(int a, int b) {							//対戦進行用関数

	int H1 = vec[a].getH(), H2 = vec[b].getH();			//各ポケモンの体力の設定
	int c = 0;							//標準入力用変数
	string C;							//エラー用標準入力用変数							
	double KA = 0.5;						//急所確率
	printf("%c[47m", ESC);



	while (1) {								//どちらかの体力が0以下になりgoto end　でループの外に飛ばない限り,ループから抜け出せない
		BattleWindow(a, b, H1, H2);

		int Q = 0;							//0,1,2,3検出用変数
		do {
			Q = 0;
			cout << "選択したい技の番号（0,1,2,3)を入力してください.入力後Enterで確定できます\n";
			cin >> C;

			if (all_of(C.cbegin(), C.cend(), isdigit)) {										//10進数かどうか検知
				if (stoi(C) == 0 || stoi(C) == 1 || stoi(C) == 2 || stoi(C) == 3)Q = 1;			//0,1,2,3かどうか検知
				else cout << "0,1,2,3以外の文字が入力されました！！もう一度入力をやり直してください\n";
			}
			else cout << "0,1,2,3以外の文字が入力されました！！もう一度入力をやり直してください\n";
		} while (Q == 0);						//0,1,2,3以外の入力ではループから出られない



		c = stoi(C);							//入力内容をintに変換
		int SE = dist1(engine);						//相手ポケモンの技選択,自分の持ってる4つの技から1つの技を選択(0,1,2,3を生成）
		double d = 0;							//急所確立生成用変数 初期化


		if (vec[a].getS() >= vec[b].getS()) {				//自分ポケモンのすばやさが高い,もしくはおなじすばやさ

			cout << endl << "いけ！" << vec[a].getName() << "の";
			if (c == 0)cout << vec2[vec[a].getW1()].getWAZA();
			else if (c == 1)cout << vec2[vec[a].getW2()].getWAZA();
			else if (c == 2)cout << vec2[vec[a].getW3()].getWAZA();
			else if (c == 3)cout << vec2[vec[a].getW4()].getWAZA();
			cout << "!" << endl;
			wait();

			d = dist2(engine);					//急所確率生成
			if (d > KA)cout << "急所に当たった！！！！！！" << endl;

			cout << "相手の" << vec[b].getName() << "は" << Damage(a, b, c, d) << "のダメージを受けた!\n";
			wait();


			H2 = H2 - Damage(a, b, c, d);				//ダメージ計算後体力の反映

			if (H2 < 0) {
				H2 = 0;
				BattleWindow(a, b, H1, H2);
				cout << "自分の" << vec[a].getName() << "の勝利!";
				goto end;
			}

			cout << "次に相手の" << vec[b].getName() << "の";
			if (SE == 0)cout << vec2[vec[b].getW1()].getWAZA();
			else if (SE == 1)cout << vec2[vec[b].getW2()].getWAZA();
			else if (SE == 2)cout << vec2[vec[b].getW3()].getWAZA();
			else if (SE == 3)cout << vec2[vec[b].getW4()].getWAZA();
			cout << "!" << endl;
			wait();

			d = dist2(engine);					//急所確率生成
			if (d > KA)cout << "急所に当たった！！！！！！" << endl;

			cout << "自分の" << vec[a].getName() << "は" << Damage(b, a, SE, d) << "のダメージを受けた!\n";
			wait();
			H1 = H1 - Damage(b, a, SE, d);				//ダメージ計算後体力の反映
			if (H1 < 0) {
				H1 = 0;
				BattleWindow(a, b, H1, H2);
				cout << "負けてしまった.....相手の" << vec[b].getName() << "の勝利!";
				goto end;
			}
		}

		if (vec[a].getS() < vec[b].getS()) {				//相手のポケモンのすばやさのほうが高い場合

			cout << "すばやい相手の" << vec[b].getName() << "の";
			if (SE == 0)cout << vec2[vec[b].getW1()].getWAZA();
			else if (SE == 1)cout << vec2[vec[b].getW2()].getWAZA();
			else if (SE == 2)cout << vec2[vec[b].getW3()].getWAZA();
			else if (SE == 3)cout << vec2[vec[b].getW4()].getWAZA();
			cout << "!" << endl;
			wait();

			d = dist2(engine);					//急所確率生成
			if (d > KA)cout << "急所に当たった！！！！！！" << endl;

			cout << "自分の" << vec[a].getName() << "は" << Damage(b, a, SE, d) << "のダメージを受けた!\n";
			wait();

			H1 = H1 - Damage(b, a, SE, d);				//ダメージ計算後体力の反映
			if (H1 < 0) {
				H1 = 0;
				BattleWindow(a, b, H1, H2);
				cout << "負けてしまった.....相手の" << vec[b].getName() << "の勝利!";
				goto end;
			}

			cout << endl << "次に" << vec[a].getName() << "の";
			if (c == 0)cout << vec2[vec[a].getW1()].getWAZA();
			else if (c == 1)cout << vec2[vec[a].getW2()].getWAZA();
			else if (c == 2)cout << vec2[vec[a].getW3()].getWAZA();
			else if (c == 3)cout << vec2[vec[a].getW4()].getWAZA();
			cout << "!" << endl;
			wait();

			d = dist2(engine);					//急所確率生成
			if (d > KA)cout << "急所に当たった！！！！！！" << endl;

			cout << "相手の" << vec[b].getName() << "は" << Damage(a, b, c, d) << "のダメージを受けた!\n";
			wait();

			H2 = H2 - Damage(a, b, c, d);				//ダメージ計算後体力の反映
			if (H2 < 0) {
				H2 = 0;
				BattleWindow(a, b, H1, H2);
				cout << "自分の" << vec[a].getName() << "の勝利!";
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

	string a, b;						//自分,相手ポケモン選択用変数
	int Q = 0;						//入力エラー検出用変数

	system("cls");						//画面クリア

	do {
		Q = 0;
		cout << "自分の使いたいポケモンを番号で選んで,番号（0,1,2,3)を入力してください.入力後Enterで確定できます\n";
		int p = 0;
		for (auto A1 : vec) {
			cout << p << "." << A1.getName() << "       \n";		//各ポケモン羅列
			p++;
		}

		cin >> a;								//自分ポケモン選択
		if (all_of(a.cbegin(), a.cend(), isdigit)) {							//10進数かどうか検知
			if (stoi(a) == 0 || stoi(a) == 1 || stoi(a) == 2 || stoi(a) == 3)Q = 1;			//0,1,2,3かどうか検知
			else cout << "0,1,2,3以外の文字が入力されました！！もう一度入力をやり直してください\n";
		}
		else cout << "0,1,2,3以外の文字が入力されました！！もう一度入力をやり直してください\n";
	} while (Q == 0);											//0,1,2,3以外の入力ではループから出られない


	cout << endl << "あなたが選んだポケモンは" << vec[stoi(a)].getName() << "です." << endl;

	do {
		Q = 0;
		cout << "次に相手のポケモンを選んで,番号（0,1,2,3)を入力してください.入力後Enterで確定できます\n";

		int p = 0;
		for (auto A1 : vec) {
			cout << p << "." << A1.getName() << "       \n";
			p++;
		}

		cin >> b;								//相手ポケモン選択
		if (all_of(b.cbegin(), b.cend(), isdigit)) {							//10進数かどうか検知
			if (stoi(b) == 0 || stoi(b) == 1 || stoi(b) == 2 || stoi(b) == 3)Q = 1;			//0,1,2,3かどうか検知
			else cout << "0,1,2,3以外の文字が入力されました！！もう一度入力をやり直してください\n";
		}
		else cout << "0,1,2,3以外の文字が入力されました！！もう一度入力をやり直してください\n";
	} while (Q == 0);											//0,1,2,3以外の入力ではループから出られない


	cout << endl << "相手のポケモンは" << vec[stoi(b)].getName() << "です.\n";
	cout << "対戦画面に映ります.少々お待ちください";
	wait();													//相手ポケモン確認用待機時間生成





	VS(stoi(a), stoi(b));											//対戦開始

}
