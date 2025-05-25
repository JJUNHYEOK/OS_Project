## (통신)보안 ... 보안은 중요합니다

# 🔓 vulnerable.c
- 취약한 코드
- 입력값 검증 부재, 메타문자와 함께 임의 명령 실행 가능

---

# 🔐 secure.c
- is_safe_input()을 통해 문자열 검사, 발견 즉시 실행 중단
- execvp() 사용 문자 해석 자체 방지

---

# 🔐 secure_wrapper.c
- 후킹(Hooking)을 사용한 보안 보조
- 동적 링커 LD_PRELOAD를 이용한 실질 호출 함수 변경

---

![exp result](.../command_injection_demo/experiment.PNG)


효과는 굉장했다 🤯
