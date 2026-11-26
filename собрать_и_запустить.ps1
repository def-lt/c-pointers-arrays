# Компилирует и запускает все программы по очереди (PowerShell)
# Русский текст из программ выводится в UTF-8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
chcp 65001 > $null

Get-ChildItem -Filter "урок*.c" | Sort-Object Name | ForEach-Object {
    # имя .exe латиницей: MinGW плохо создаёт файлы с русскими именами
    $num = ($_.BaseName -replace '\D', '').Substring(0, 2)
    $exe = "lesson$num.exe"
    Write-Host "`n=== $($_.Name) ===" -ForegroundColor Yellow
    Write-Host "> gcc -std=c11 -Wall -Wextra $($_.Name) -o $exe" -ForegroundColor DarkGray
    gcc -std=c11 -Wall -Wextra $_.Name -o $exe
    if (Test-Path ".\$exe") {
        Write-Host "> .\$exe" -ForegroundColor DarkGray
        & ".\$exe"
    } else {
        Write-Host "Файл $exe не создан (код gcc: $LASTEXITCODE)" -ForegroundColor Red
    }
}
