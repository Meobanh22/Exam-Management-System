import json
import random
import os
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))


LAST_NAMES = [
    ("Nguyễn", 0.38), ("Trần", 0.11), ("Lê", 0.095), ("Phạm", 0.07),
    ("Hoàng", 0.05), ("Huỳnh", 0.03), ("Phan", 0.045), ("Vũ", 0.039),
    ("Võ", 0.03), ("Đặng", 0.021), ("Bùi", 0.02), ("Đỗ", 0.014),
    ("Hồ", 0.013), ("Ngô", 0.013), ("Dương", 0.01), ("Lý", 0.005),
    ("Đinh", 0.008), ("Đoàn", 0.007), ("Lâm", 0.006), ("Trịnh", 0.006),
    ("Mai", 0.005), ("Đào", 0.005), ("Cao", 0.004), ("Tạ", 0.003)
]

MID_NAMES_MALE = [
    "Văn", "Hữu", "Đức", "Minh", "Quốc", "Gia", "Hoàng", "Tuấn", "Anh",
    "Công", "Thành", "Xuân", "Quang", "Thanh", "Đình", "Thế", "Duy",
    "Mạnh", "Trung", "Bảo", "Ngọc", "Tiến", "Trọng", "Đăng", "Nhật",
    "Phúc", "Khánh", "Hải", "Thái", "Việt", "Chí", "Tấn", "Bá"
]

MID_NAMES_FEMALE = [
    "Thị", "Ngọc", "Thu", "Thanh", "Minh", "Phương", "Thùy", "Anh",
    "Bảo", "Khánh", "Hoàng", "Mỹ", "Kim", "Hồng", "Lan", "Mai", "Hải",
    "Yến", "Tuyết", "Ánh", "Thảo", "Diệu", "Cẩm", "Kiều", "Tường",
    "Bích", "Quỳnh", "Gia", "Nhật", "Như", "Hà", "Vân", "Xuân"
]

FIRST_NAMES_MALE = [
    "Anh", "Minh", "Huy", "Dũng", "Hoàng", "Tuấn", "Đức", "Mạnh", "Nam", "Long",
    "Hùng", "Kiên", "Cường", "Hiếu", "Đạt", "Quân", "Duy", "Thành", "Phong",
    "Trung", "Khánh", "Sơn", "Tùng", "Việt", "Bảo", "Phúc", "Khang", "Khoa",
    "Hải", "Thắng", "Lâm", "Bình", "Tài", "Toàn", "Thịnh", "Hưng", "Vinh",
    "Nghĩa", "Trí", "Lộc", "Nhân", "An", "Bách", "Khôi", "Tân", "Triết", "Lâm"
]

FIRST_NAMES_FEMALE = [
    "Anh", "Linh", "Trang", "Thảo", "Phương", "Nhi", "Ngọc", "Ngân", "Hương",
    "Huyền", "Hà", "My", "Mai", "Lan", "Vy", "Trinh", "Yến", "Nhung", "Quỳnh",
    "Thư", "Trâm", "Tiên", "Duyên", "Giang", "Hạnh", "Hoa", "Vân", "Châu",
    "Ánh", "Chi", "Dung", "Đào", "Hiền", "Ly", "Oanh", "Phượng", "Tâm",
    "Thanh", "Thúy", "Thủy", "Trà", "Tú", "Uyên", "Nga", "Diệp"
]


def generate_name():
    surnames, weight = zip(*LAST_NAMES)
    last_name = random.choices(surnames, weights=weight, k=1)[0]

    gender = random.choices(["M","F"], [0.7, 0.3])[0]
    mid = MID_NAMES_MALE if gender == "M" else MID_NAMES_FEMALE
    first = FIRST_NAMES_MALE if gender == "M" else FIRST_NAMES_FEMALE

    first_name = random.choice(first)
    if random.random() < 0.75:
        mid_name = random.choice(mid)
    else:
        m1 = random.choice(mid)
        m2 = random.choice(mid)
        mid_name = f"{m1} {m2}"
    return (f"{last_name} {mid_name} {first_name}", gender)

def generate_studentId(year):
    return year+f"{random.randint(10000,20000)}" if year == "2026" or year == "2025" else year+f"{random.randint(1000,9999)}"

with open(os.path.join(SCRIPT_DIR, "FaMI.json"), "r", encoding="utf-8") as f:
    data_fami = json.load(f)
with open(os.path.join(SCRIPT_DIR, "SoICT.json"), "r", encoding="utf-8") as f:
    data_soict = json.load(f)

def generate_subjects(num_subjects, school):
    data = data_fami if school == "FaMI" else data_soict
    return random.sample(data, num_subjects)

used_id = set()
def generate_student():
    year = random.randint(2003, 2008)
    month = random.randint(1, 12)
    day = random.randint(1, 28) if month == 2 else random.randint(1, 30) if month in [4, 6, 9, 11] else random.randint(1, 31)
    dob = f"{day:02d}/{month:02d}/{year}"

    while True:
        studentId = generate_studentId(str(year+18))
        if studentId not in used_id:
            break
    used_id.add(studentId)
    name, gender = generate_name()
    gender = "Female" if gender == "F" else "Male"
    school = random.choices(["FaMI","SoICT"],[0.20,0.80])[0]
    num_subjects = random.choices(range(1,7),[0.05,0.10,0.20,0.30,0.20,0.15])[0]
    subjectIDs = generate_subjects(num_subjects, school)
    subjectIDs = [s["code"] for s in subjectIDs]
    return {
        "studentId": studentId,
        "name": name,
        "gender": gender,
        "dob": dob,
        "school": school,
        "subjectIDs": subjectIDs
    }

def generate_room():
    n = random.randint(30,40)
    rooms = []
    for i in range(n):
        room_name = f"P{i+1:02d}"
        rows = random.randint(5,10)
        cols = random.randint(6,8)
        rooms.append({"roomId": room_name, "rows": rows, "cols": cols})
    return rooms

with open(os.path.join(SCRIPT_DIR, "room.json"), "w", encoding="utf-8") as f:
    json.dump(generate_room(), f, ensure_ascii=False, indent=4)
with open(os.path.join(SCRIPT_DIR, "student.json"), "w", encoding="utf-8") as f:
    json.dump([generate_student() for _ in range(8000)], f, ensure_ascii=False, indent=4)