package mPrivate;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class myTest {
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		List<Student> list = new ArrayList<Student>(10);
		list.add(new Student(1, "jj"));
		list.add(new Student(0, "ww"));
		list.add(new Student(0, "kk"));
		list.add(new Student(2, "ll"));
		Collections.sort(list); // 内部比较器:要排序的对象实现Comparable接口,可以对自身进行比较
		System.out.println(list);

		List<Teacher> t = new ArrayList<Teacher>(10);
		t.add(new Teacher(1, 12));
		t.add(new Teacher(0, 13));
		t.add(new Teacher(0, 14));
		t.add(new Teacher(2, 15));
		Collections.sort(t, new StudentComparator()); // 外部比较器:通过实现Comparator接口
		System.out.println(t);
	}
}

@SuppressWarnings("rawtypes")
class Student implements Comparable {
	int num;

	String name;

	public Student(int num, String name) {
		this.num = num;
		this.name = name;
	}

	@Override
	public String toString() {
		return "\r\tnum:" + num + " name:" + name + "\r";
	}

	public int compareTo(Object o) {
		Student tmp = (Student) o;
		int result = tmp.num > num ? 1 : (tmp.num == num ? 0 : -1);
		if (result == 0) {
			result = tmp.name.indexOf(0) > name.indexOf(0) ? 1 : -1;
		}
		return result;
	}
}

class Teacher {
	int num;

	double salary;

	public Teacher(int num, double salary) {
		this.num = num;
		this.salary = salary;
	}

	@Override
	public String toString() {
		return "\r\tnum:" + num + " salary:" + salary + "\r";
	}
}

@SuppressWarnings("rawtypes")
class StudentComparator implements Comparator {//比较器

	public int compare(Object o1, Object o2) {
		Teacher t1 = (Teacher) o1;
		Teacher t2 = (Teacher) o2;
		int result = t1.num > t2.num ? 1 : (t1.num == t2.num ? 0 : -1);
		return result = result == 0 ? (t1.salary < t2.salary ? 1 : -1) : result;
	}

}
