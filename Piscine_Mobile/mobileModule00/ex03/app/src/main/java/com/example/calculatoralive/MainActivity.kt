package com.example.calculatoralive

import android.os.Bundle
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.CenterAlignedTopAppBar
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.material3.TextButton
import androidx.compose.material3.TopAppBarDefaults
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableDoubleStateOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.text.style.TextOverflow
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.lifecycle.ViewModel
import com.example.calculatoralive.ui.theme.CalculatorAliveTheme
import androidx.lifecycle.viewmodel.compose.viewModel
import java.lang.Math.floor

class CalculatorViewModel : ViewModel() {
    var expression by mutableStateOf(" ")
        private set

    var result by mutableDoubleStateOf(0.0)
        private set

//    var error by mutableStateOf<String?>(null)
//        private set

    fun onButtonClick(label: String) {
        var localRes = result
        val currentNumber: String = expression.split("+", "-", "*", "/").last()
        if (label == "AC") {
            expression = " "
            result = 0.0
        } else if (label == "C") {
            if (expression.last() != ' ')
                expression = expression.dropLast(1)
        } else {
            Log.d("TAG", "\'$expression\'")   // prints to Android Logcat
            Log.d("TAG", label)   // prints to Android Logcat
            Log.d("expression.last()", "${expression.last()}")
            Log.d("label.last()", "${label.last()}")

            if (label == "=" && expression != " ") {
                if (isOp(expression.last())) { return }
                Calculate(
                    expression = expression,
                    result = localRes,
                    onResultChange = { localRes = it })
                result = Math.round(localRes * 1000000000.0) / 1000000000.0
                return
            } else if (label == "=" && expression == " " || label == "") { return }
            if ((expression == "0" || expression == " ") && (label == "0" || label == "+" || label == "/" || label == "*")) {return}

            if (expression.last() == '-' && label.last() !in '0'..'9' && label != "00") { return }
            if ((expression.last() == '-' && label.last() !in '0'..'9' && label != "00") ||
                (expression.last() == '-' && label == "-") ||
                (label == "00" && expression.last() != '.' && expression.last() !in '0'..<':' )){ return }
            if ((expression == " " || isOp(expression.last())) && (label == ".")) {
                expression += "0."
                Log.d("TAG for '.'", expression)   // prints to Android Logcat
                return
            } else if (
                ((expression.last() == '+' || expression.last() == '*' || expression.last() == '/')) && (label == "+" || label == "*" || label == "/" )
            ) {
                expression = expression.dropLast(1) + label
                return
            } else if((expression.last() == '-' && ( expression[expression.length - 2] == '+' || expression[expression.length - 2] == '*' || expression[expression.length - 2] == '/'))
                && (label == "+" || label == "*" || label == "/" )) { return }
            else if (label == "." && currentNumber.contains(".")) return

            expression += label
        }
    }

}

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            CalculatorAliveTheme {
                val viewModel: CalculatorViewModel = viewModel()

                Scaffold(
                    modifier = Modifier.fillMaxSize(),
                    topBar = { TopAppBar() }  // ← belongs here
                ) { innerPadding ->
                    Column (
                        modifier = Modifier
                            .fillMaxSize()
                            .padding(innerPadding),
                        verticalArrangement = Arrangement.SpaceBetween
                    ) {
                        ResultFields(expression = viewModel.expression,
                            result = viewModel.result,
                            modifier = Modifier
//                                .fillMaxSize()
                                .fillMaxWidth()
                                .weight(4f)
                        )
                        Keypad(onButtonClick = { label -> viewModel.onButtonClick(label) },
                            modifier = Modifier
                                .fillMaxWidth()
                                .weight(6f)
                        )
                    }
                }
            }
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun TopAppBar() {
    CenterAlignedTopAppBar(
        colors = TopAppBarDefaults.topAppBarColors(
            containerColor = MaterialTheme.colorScheme.primaryContainer,
            titleContentColor = MaterialTheme.colorScheme.primary,
        ),
        title = {
            Text(
                "Calculator",
                maxLines = 1,
                overflow = TextOverflow.Ellipsis
            )
        }
    )
}

@Composable
fun ResultFields(
    expression: String,
    result: Double,
    modifier: Modifier = Modifier) {

    Column (
        modifier = modifier
            .fillMaxSize()
            .padding(8.dp),
        verticalArrangement = Arrangement.SpaceEvenly
    ) {
        Text(
            text = expression,
            fontSize = 50.sp,
            textAlign = TextAlign.End,
            modifier = Modifier.align(Alignment.End)
                .fillMaxWidth()
        )

        Text(
            text = "%.8f".format(result).trimEnd('0').trimEnd('.'),
            fontSize = 50.sp,
            textAlign = TextAlign.End,
            modifier = Modifier.align(Alignment.End)
                .fillMaxWidth()
        )
    }

}
@Composable
fun Keypad(onButtonClick: (String) -> Unit, modifier: Modifier = Modifier) {

    val buttons1 = listOf("7", "8", "9", "C", "AC")
    val buttons2 = listOf("4", "5", "6", "+", "-")
    val buttons3 = listOf("1", "2", "3", "*", "/")
    val buttons4 = listOf("0", ".", "00", "=", "")
    val buttons = listOf(buttons1, buttons2, buttons3, buttons4)

    Column(
        modifier = modifier
            .fillMaxSize()
    ) {
        buttons.forEach {
            Row(modifier = Modifier
                .fillMaxSize()
                .weight(1f),
                horizontalArrangement = Arrangement.Center
            ) {
                it.forEach { label ->
                    val textColor = when (label) {
                        "AC", "C" -> Color.Red
                        "+", "-", "*", "/" -> Color.White
                        else -> Color.Gray
                    }
                    TextButton(onClick = {
                        Log.d("TAG", "Button $label clicked")
                        onButtonClick(label)
                        },
                        modifier = modifier
                            .fillMaxSize()
                            .weight(1f)
                    ) {
                        Text(
                            text = label,
                            fontSize = 30.sp,
                            color = textColor
                        )
                    }
                }
            }
        }
    }
}

fun Calculate(
    expression: String,
    result: Double,
    onResultChange: (Double) -> Unit,
) {
    // Convert to RPN
    val numList = mutableListOf<String>()
    val opList = mutableListOf<String>()
    var lastChar : Char = ' '
    var i : Int = 0
    var collectNum : Boolean = true
    var num : String = ""
    val expression_cp = expression + "+"

    while (i < expression_cp.length) {
        val ch = expression_cp[i]
        if (ch == ' ') {
            i++
            continue
        }

        if (isOp(ch)) {
            collectNum = false
            if(isOp(lastChar)) { collectNum = true}
        } else {
            collectNum = true
        }

        if (collectNum) {
            num += ch
        } else {
            numList.add(num)
            num = ""
            if (!opList.isEmpty() && (ch == '-' || ch == '+') && (opList.last() == "*" || opList.last() == "/") || i + 1 == expression_cp.length) {
                while(!opList.isEmpty()) {
                    numList.add(opList.last())
                    opList.removeAt(opList.lastIndex)
                }
            }
            opList.add(ch.toString())
        }
        lastChar = ch
        i++
    }
    Log.d("TAG", "RPN list $numList")

    val calcList = mutableListOf<Double>()
    for (it in numList) {
        if (it.toDoubleOrNull() != null )
            calcList.add(it.toDouble())
        else {
            if (calcList.size >= 2) {
                val num1 = calcList.last()
                calcList.removeAt(calcList.lastIndex)
                val num2 = calcList.last()
                calcList.removeAt(calcList.lastIndex)
                calcList.add(calculate(num2, num1, it))
            }
        }
    }
    onResultChange(calcList[0])
    return
}

fun isOp(ch : Char) : Boolean {
    if (ch == '+' || ch == '/' || ch == '*' || ch == '-')
        return true
    return false
}

fun calculate( num1 : Double, num2 : Double, op : String) : Double {
    when (op) {
        "*" -> return num1 * num2
        "+" -> return num1 + num2
        "-" -> return num1 - num2
        "/" -> if (num2 == 0.0) {
            return 0.0
        } else return num1 / num2
    }
    return 0.0
}


@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    CalculatorAliveTheme{
        Scaffold(
            modifier = Modifier.fillMaxSize(),
            topBar = { TopAppBar() }  // ← belongs here
        ) { innerPadding ->
            Column (
                modifier = Modifier.fillMaxHeight().padding(16.dp).padding(innerPadding),
                verticalArrangement = Arrangement.Bottom
            ) {

            }
        }
    }
}