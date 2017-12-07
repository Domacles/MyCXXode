 1.声明一个Map :

   Map map = new HashMap();

2 .向map中放值 ，注意： map是key-value的形式存放的，如：

       map.put("sa","dd");

3 .从map中取值 :

    String str = map.get("sa").toString,

    结果是： str = "dd'

4 .遍历一个map,从中取得key和value :

    Map m= new HashMap();

    for(Object obj : map.keySet()){

          Object value = map.get(obj );

    }
