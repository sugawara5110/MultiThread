# MultiThread


MultiThread th;

th.setFunc(スレッド化したい関数1);(max10個)

th.setFunc(スレッド化したい関数2);

th.start();//スレッド生成

//ループ

th.wait();//全スレッド1ループ終わるまで待機

//ループ

th.end();//後始末