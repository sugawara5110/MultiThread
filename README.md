# MultiThread

////同期有り(繰り返し処理)////

MultiThread th;

th.setFunc(スレッド化したい関数1);(max10個)

th.setFunc(スレッド化したい関数2);

th.start();//スレッド生成

//ループ

th.wait();//全スレッド1ループ終わるまで待機

//ループ

th.end();//後始末


////同期無し(繰り返し無し)////

MultiThread_NotSync th;

th.setFunc(スレッド化したい関数1);(max10個)

th.setFunc(スレッド化したい関数2);

th.start();//スレッド生成

//ループ

if(Status())break;//全てのスレッドで処理が完了したらtrueが返る

//ループ

th.end();//後始末
