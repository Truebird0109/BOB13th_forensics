# 1. add nbo 과제
## 과제
32 bit 숫자가 파일에 4바이트의 크기로 저장되어 있다(network byte order). 2개의 파일로부터 숫자를 읽어 들여 그 합을 출력하는 프로그램을 작성하라.
### 실행 방법
```
syntax : add-nbo <file1> <file2>
sample : add-nbo a.bin b.bin
```
### example 
```
$ echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
$ echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin
$ ./add-nbo thousand.bin five-hundred.bin
1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)
```
### 결과
![스크린샷 2024-07-18 153146](https://github.com/user-attachments/assets/58670186-88fe-44b0-a60b-fe323b507bbb)

