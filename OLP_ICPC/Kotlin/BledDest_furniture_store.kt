fun main() = repeat(readln().toInt()) {
  val n = readln().toInt()
  val a = readln().split(" ").map { it.toInt() }
  val p = a.runningReduce { x, y -> minOf(x, y) }
  val ans = (1..n).filter { i -> a[i - 1] != p[i - 1] }
  println(ans.size)
  println(ans.joinToString(" "))    
}