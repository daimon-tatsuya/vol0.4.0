#ifndef INCLUDED_OBJ2D
#define INCLUDED_OBJ2D

#include <list>

//******************************************************************************
//
//
//      obj2d.h
//
//
//******************************************************************************

//------< 定数 >----------------------------------------------------------------

//------< 構造体 >---------------------------------------------------------------

//==============================================================================
//
//      OBJ2D
//
//==============================================================================
//class OBJ2D
//{
//public:
//
//    // スプライト関連
//    Sprite* data;           // スプライトポインタ
//    VECTOR2 texPos;         // 画像位置
//    VECTOR2 texSize;        // 画像サイズ
//    VECTOR2 texPivot;       // 画像の基準点
//    int     anime;          // アニメーション用（仮）
//
//    // OBJ2Dのタイプ・存在フラグ
//    int     type;           // タイプ
//    BOOL    exist;          // 存在フラグ
//
//    // 汎用的なもの
//    VECTOR2 pos;            // 位置
//    VECTOR2 scale;          // スケール
//    float   angle;          // 角度
//    VECTOR4 color;          // 色（xyzwそれぞれrgba）
//    float   radius;         // 半径
//    int     state;          // 状態遷移用
//    int     timer;          // タイマー
//    VECTOR2 speed;          // 速度
//    int     cnt;            // 汎用カウンタ（使い方は自由）
//    BOOL    hostilityFg;    // 敵フラグ（今回から追加）
//
//    // 特殊なもの
//    BOOL    grndFg;         // 地上フラグ（地上のものはTRUE）
//    float   rotate;         // 旋回する角度
//    OBJ2D*  parent;         // 親オブジェクトを指すポインタ
//    VECTOR2 rpos;           // 相対的な位置（relative position)
//    int     hp;             // ヒットポイント
//    int     atk;            // 攻撃力
//    int     damageTimer;    // ダメージタイマー
//    int     score;          // この敵を倒したら何点入るか
//};

// 前方宣言
class OBJ2D;

//------< プロトタイプ宣言 >-----------------------------------------------------
//
// 移動アルゴリズムクラス（抽象クラス）
class MoveAlg
{
public:
    virtual void move(OBJ2D* obj) = 0;  // 純粋仮想関数を持つので、MoveAlg型のオブジェクトは宣言できない（派生させて使う）
};

// 消去アルゴリズムクラス（抽象クラス）
class EraseAlg
{
public:
    virtual void erase(OBJ2D* obj) = 0; // 上と同様
};

class OBJ2D
{
public:
    //非静的メンバ変数の初期化（C++11）
    MoveAlg*                mvAlg = nullptr;      // 移動アルゴリズム
    EraseAlg*               eraseAlg = nullptr;   // 消去アルゴリズム

    GameLib::SpriteData*    data = nullptr;         // スプライトデータ
    GameLib::Anime          anime ;                 // アニメーションクラス

    VECTOR2                 position  ;             // 位置
    VECTOR2                 scale = {1, 1};         // スケール
    float                   angle = 0;              // 角度
    VECTOR4                 color ;                 // 描画色
    VECTOR2                 size = {1, 1};          // あたり用サイズ（縦横）
    
    float                   velocity = 0;           // 速度
    VECTOR2                 speed ;                 // 瞬間の移動量ベクトル
    int                     state = 0;              // ステート
    int                     timer = 0;              // タイマー
    int                     param = 0;              //汎用パラメータ
    int                     type = 0;               // タイプ
    int                     inversion;              //反転
//<<<<<<< HEAD
    float                   GROUND_POS_Y;           //地面(initで決める)
//=======
   
//<<<<<<< HEAD
//<<<<<<< HEAD
     int                    no;                     //汎用
//>>>>>>> 0ecd60dfe11cdb69557f833ea8a896513ec56bde
//=======
   //int              no;                     //番号振り分け
//>>>>>>> 0109f21d0b202314af7c1d09622182140ff74ef5
//=======
  //  int                     no;                     //番号振り分け
//>>>>>>> a24f0345bfffecba1977123f24777fafc7059949

    int                     iWork[16] ;             // 汎用（使い方は自由）
    float                   fWork[16] ;             // 汎用（使い方は自由）
    bool                    bWork[16] ;             // 汎用（使い方は自由）    
                      
    int                     jumpTimer = 0;          // 長押しジャンプタイマー
    int                     mutekiTimer = 0;        // 無敵タイマー
    int                     damageTimer = 0;        // ダメージタイマー

    GameLib::fRECT          hitRect = {};           // あたり判定RECT

    bool                    judgeFlag = false;      // あたり判定の有無（true:有り / false:無し）
    bool                    isDrawHitRect = false;  // あたり判定描画フラグ
    bool                    hashigoFlag = false;    // はしごフラグ
    bool                    hasSword = false;       // 剣を持っているか（true:所持 / false:無し）

    int                     command = 0;            // 他のオブジェクトからのコマンド
    VECTOR2                 delta ;                 // 移動量の差分

    GameLib::AnimeData*     animeData = nullptr;    // アニメーションデータ
    bool                    onGround = false;       // 地面フラグ（地上にいる）
    float                     xFlip;                  // x軸の反転
    //bool                    kabeFlag = false;     // 壁フラグ（一歩先が壁）
    //bool                    gakeFlag = false;     // 崖フラグ（一歩先が崖）
 
    BOOL    exist;                                  // 存在フラグ

    bool caughtFlg = false;    //trueの時持ち上げられてる

    bool throwFlg = false;

    int                     count = 0;

    VECTOR2 initVelocity = VECTOR2(0 ,0);//初速度
public:
    // メンバ関数
   // OBJ2DC();        // コンストラクタ

    //void clear();   // メンバ変数のクリア
    void move();    // 移動
    void draw();    // 描画
    //bool animeUpdate();                         // アニメーションのアップデート
    bool animeUpdate(AnimeData* animeData);                         // アニメーションのアップデート

    void drawHitRect(const VECTOR4&);           // 当たり判定描画
};
OBJ2D* searchSet(OBJ2D[], int, int, VECTOR2);
BOOL areaCheck(OBJ2D*, float);

// OBJ2DManagerクラス
class OBJ2DManager
{
protected:
    std::list<OBJ2D>  objList; // リスト（OBJ2Dの配列のようなもの）
public:
    // デストラクタ
    ~OBJ2DManager();

    void init();    // 初期化
    void update();  // 更新
    void draw();    // 描画

    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos = VECTOR2(0, 0)); // objListに新たなOBJ2Dを追加する
    std::list<OBJ2D>* getList() { return &objList; }                // objListを取得する
};

//template<class getData>
void readData(std::string fileName, float& data);

#endif // !INCLUDED_OBJ2D
