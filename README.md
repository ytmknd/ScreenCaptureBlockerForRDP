# ScreenCaptureBlockerForRDP

## これは何？
リモートデスクトップウインドウに表示されている内容を、Print Screenキー等でキャプチャーできなくするためのプログラムです（Windows 7/8/8.1/10用）

## 説明
インストールすると、PC起動時（ログオン時）にタスクトレイに常駐します。  
この状態でスクリーンショットを取ると、リモートデスクトップウインドウやRemoteAppウインドウの部分だけが黒塗りになったスクリーンショットが取れます。  
Print ScreenキーやSnipping Toolを使用した画面キャプチャー、Microsoft Officeの「スクリーンショット」機能を使った場合が対象です。  

## デモ
![DEMO](https://raw.githubusercontent.com/ytmknd/ScreenCaptureBlockerForRDP/images/demo.gif)

## ビルド方法
* Visual Studio 2017、WiX Toolset が必要です。
* ソリューションファイル（ScreenCaptureBlockerForRDP.sln）を Visual Studio から開き、ビルドしてください。
* 必要に応じて、プラットフォーム（x86 or x64）を選んでビルドしてください。
  x86でビルドした場合は32ビット版、x64でビルドした場合は64ビット版のビルドになります。
* インストーラーは、Setup フォルダ（32ビット版）、Setupx86_64 フォルダ（64ビット版）の配下に作成されます。

## 注意点
* 32ビットOSは32ビット版のインストーラーを、64ビットOSは64ビット版のインストーラーを使用してインストールしてください。
* Windows 7ではAeroを有効にしておく必要があります。
* クリップボードの共有は停止しておきましょう。例えば、クリップボードの共有が有効で、全画面表示でリモートデスクトップを使用中にPrint Screenキーを押した場合、クリップボードにリモートコンピューターの画面がキャプチャーされます。これは、リモートコンピューター側で実行された画面キャプチャが、クリップボード共有を経由してローカルコンピューターに転送されてしまうために起こります。

## ライセンス
MIT

## 謝辞
アイコンイメージに Ionicons を利用させて貰っています（Ionicons is licensed under the MIT license).
