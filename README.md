# face_detect
- [x] find face on picture
- [x] blur founded box with face
- [x] recursive search all valid file(.jpg|.png) and put it to image processing
- [x] create shared lib in linux 31.08.19 update - lib placed in branch *libfdetect*
- [x] save coords to json update 1.09.19 - create with boost::property_tree::ptree
- [x] json multi write ready
- [x] shared lib ready (branch *libfdetect*)
- [x] save resize pictures ready
- [x] create .dep package ready (*libfdetect_dep*)
- [ ] add tests
---
# warnings
1) .json file with coords has named as original picture - boost function *json_write* rewrite nodes
2) works on Ubuntu 18.04
3) compiler GCC 7.4.1
4) cmake version - 3.10
5) boost version - 1.65.1
6) OpenCV version 3.4

---

# screenshot

![example](https://github.com/IllidanSR/face_detect/blob/master/pic/example.png)

result:
![pic1](https://github.com/IllidanSR/face_detect/blob/master/pic/cfsawarenessday_1024px.jpg)
![pic2](https://github.com/IllidanSR/face_detect/blob/master/pic/bg-people.jpg)


# Result example
cfsawarenessday_1024px.jpg.json:
```javascript
{
    "0": [
        "366",
        "62",
        "472",
        "168"
    ],
    "1": [
        "47",
        "97",
        "140",
        "190"
    ],
    "2": [
        "182",
        "148",
        "308",
        "274"
    ],
    "3": [
        "667",
        "155",
        "789",
        "277"
    ],
    "4": [
        "368",
        "240",
        "526",
        "398"
    ],
    "5": [
        "694",
        "420",
        "827",
        "553"
    ],
    "6": [
        "79",
        "421",
        "167",
        "509"
    ]
}
```
