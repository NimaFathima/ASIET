class Test{
	protected void finalize(){
		System.out.println("object is garbage collected");
	}
	public static void main(String args[]){
		Test s1 =new Test();
		Test s2 =new Test();
		s1=null;
		s2=null;
		System.gc();
	}
}
