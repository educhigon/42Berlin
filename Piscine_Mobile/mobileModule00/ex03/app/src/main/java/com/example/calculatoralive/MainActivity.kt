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
import androidx.compose.runtime.internal.StabilityInferred
import androidx.compose.runtime.mutableDoubleStateOf
import androidx.compose.runtime.mutableIntStateOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.text.style.TextOverflow
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.calculatoralive.ui.theme.CalculatorAliveTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            CalculatorAliveTheme {
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
                        var expression by remember { mutableStateOf(" ") }
                        var result by remember { mutableDoubleStateOf(0.0) }

                        ResultFields(expression = expression,
                            result = result,
                            modifier = Modifier
//                                .fillMaxSize()
                                .fillMaxWidth()
                                .weight(4f)
                        )
                        Keypad(expression = expression,
                            onExpressionChange = { it -> expression = it },
                            result = result,
                            onResultChange = { it -> result = it },
                            modifier = Modifier
//                                .fillMaxSize()
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
            text = "$result",
            fontSize = 50.sp,
            textAlign = TextAlign.End,
            modifier = Modifier.align(Alignment.End)
                .fillMaxWidth()
        )
    }

}
@Composable
fun Keypad(
    expression: String,
    onExpressionChange: (String) -> Unit,
    result: Double,
    onResultChange: (Double) -> Unit,
    modifier: Modifier = Modifier) {

    val buttons1 = listOf("7", "8", "9", "C", "AC")
    val buttons2 = listOf("4", "5", "6", "+", "-")
    val buttons3 = listOf("1", "2", "3", "*", "/")
    val buttons4 = listOf("0", ".", "00", "=", "")
    val buttons = listOf(buttons1, buttons2, buttons3, buttons4)

    var localExp = expression
    var localRes = result
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
                        UpdateCalc(expression = localExp,
                            onExpressionChange = { localExp = it },
                            result = localRes,
                            onResultChange = { localRes = it },
                            label = label)
                        onExpressionChange(localExp)
                        onResultChange(localRes)
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

fun UpdateCalc(
    expression: String,
    onExpressionChange: (String) -> Unit,
    result: Double,
    onResultChange: (Double) -> Unit,
    label: String ) {

    var localRes = result
    if (label == "AC") {
        onExpressionChange(" ")
        onResultChange(0.0)
    } else if (label == "C") {
        onExpressionChange(expression.dropLast(1))
    } else {
        Log.d("TAG", expression)   // prints to Android Logcat
        Log.d("TAG", label)   // prints to Android Logcat

        if (label == "=") {
            Calculate(
                expression = expression,
                result = localRes,
                onResultChange = { localRes = it })
            onResultChange(Math.round(localRes * 1000000000.0) / 1000000000.0)
//            onResultChange(0.0)
//            onExpressionChange(localRes.toString())
            return
        }
        if (expression == "0" || expression == " ") {
            if (label == "0" || label == "+" || label == "/" || label == "*") {
                onExpressionChange(expression)
                return
            }
        } else if (
            (expression == "-" && label.last() !in '0'..<':' && label != "00") ||
            (expression.last() == '-' && label == "-") ||
            (label == "00" && expression.last() != '.' && expression.last() !in '0'..<':' )
        ){
            onExpressionChange(expression)
            return
        } else if (
            ((expression.last() == '+' || expression.last() == '*' || expression.last() == '/') ||
            (expression.last() == '-' && ( expression[expression.length - 2] == '+' || expression[expression.length - 2] == '*' || expression[expression.length - 2] == '/')))
            && (label == "+" || label == "*" || label == "/" )
            ) {
            onExpressionChange(expression.dropLast(1) + label)
            return
        }
        onExpressionChange(expression + label)
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
            if(isOp(lastChar) || ch == ' ') { collectNum = true}
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
        "/" -> return num1 / num2
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