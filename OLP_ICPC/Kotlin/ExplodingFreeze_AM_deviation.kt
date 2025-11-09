fun main(args: Array<String>) {
    repeat(readLine()!!.toInt()) {
        println(Math.min(readLine()!!.split(" ").map { it.toInt() }.sum() % 3, 1))
    }
}