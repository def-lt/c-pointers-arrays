# Компилирует и запускает все программы по очереди (PowerShell)
Get-ChildItem -Filter "урок*.c" | Sort-Object Name | ForEach-Object {
    $exe = $_.BaseName + ".exe"
    Write-Host "`n=== $($_.Name) ===" -ForegroundColor Yellow
    gcc -std=c11 -Wall -Wextra $_.Name -o $exe
    if ($LASTEXITCODE -eq 0) { & ".\$exe" }
}
