const char* root_ca= \
"-----BEGIN CERTIFICATE-----\n" \
"MIIGfzCCBWegAwIBAgIQCf6k9QnQdLE64pGrNWAEGzANBgkqhkiG9w0BAQsFADBZ\n" \
"MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMTMwMQYDVQQDEypS\n" \
"YXBpZFNTTCBUTFMgRFYgUlNBIE1peGVkIFNIQTI1NiAyMDIwIENBLTEwHhcNMjIw\n" \
"MTIwMDAwMDAwWhcNMjMwMTMxMjM1OTU5WjAZMRcwFQYDVQQDEw5tYXBhLmlkc2pt\n" \
"ay5jejCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAMw0wjcsLAHBIada\n" \
"enFSer8Lwf7UCZk1EVuobh0mghcOIpSPmRJLg850317/kZB28fniQmxcTRLTSx+p\n" \
"B83NS0RdoR4l9am0rHhYTE4m17xk6XzWtXvwiGvD9aDwXySPQKOQvhUQkvtekJGQ\n" \
"hpFy5538K/6JFRvCf7c6vACsdJplIH5A9DIspxWeWgFjeG3fYbQfS2RbnNMXZIs5\n" \
"0AmdWevWRkYwRIU1xBEA/EARRygL/MHuHoT/CMGT6FICC4T+QrwccMQWYMUpCF6h\n" \
"fZgtdOvyLOmKCPK6G0m6t+oXur6VsM3ch5OxfLTsf8IA5Ys8wlygVTHER4sdKlDC\n" \
"aQcPAqsCAwEAAaOCA4EwggN9MB8GA1UdIwQYMBaAFKSN5b58eeRwI20uKTStI1jc\n" \
"9TF/MB0GA1UdDgQWBBQ8+EPuG9G+M2xxa/NhUOKIU4G8TjAZBgNVHREEEjAQgg5t\n" \
"YXBhLmlkc2ptay5jejAOBgNVHQ8BAf8EBAMCBaAwHQYDVR0lBBYwFAYIKwYBBQUH\n" \
"AwEGCCsGAQUFBwMCMIGbBgNVHR8EgZMwgZAwRqBEoEKGQGh0dHA6Ly9jcmwzLmRp\n" \
"Z2ljZXJ0LmNvbS9SYXBpZFNTTFRMU0RWUlNBTWl4ZWRTSEEyNTYyMDIwQ0EtMS5j\n" \
"cmwwRqBEoEKGQGh0dHA6Ly9jcmw0LmRpZ2ljZXJ0LmNvbS9SYXBpZFNTTFRMU0RW\n" \
"UlNBTWl4ZWRTSEEyNTYyMDIwQ0EtMS5jcmwwPgYDVR0gBDcwNTAzBgZngQwBAgEw\n" \
"KTAnBggrBgEFBQcCARYbaHR0cDovL3d3dy5kaWdpY2VydC5jb20vQ1BTMIGFBggr\n" \
"BgEFBQcBAQR5MHcwJAYIKwYBBQUHMAGGGGh0dHA6Ly9vY3NwLmRpZ2ljZXJ0LmNv\n" \
"bTBPBggrBgEFBQcwAoZDaHR0cDovL2NhY2VydHMuZGlnaWNlcnQuY29tL1JhcGlk\n" \
"U1NMVExTRFZSU0FNaXhlZFNIQTI1NjIwMjBDQS0xLmNydDAJBgNVHRMEAjAAMIIB\n" \
"fgYKKwYBBAHWeQIEAgSCAW4EggFqAWgAdQDoPtDaPvUGNTLnVyi8iWvJA9PL0RFr\n" \
"7Otp4Xd9bQa9bgAAAX53u06qAAAEAwBGMEQCIGP5ZJfxy5wjd0Iuv0aTkJSsAJHP\n" \
"45ZtB4KBRAH5PHT6AiBszDrZYf5ObUxbkubIICqAzx+610U66ZiJt5xO+dt9mgB3\n" \
"ADXPGRu/sWxXvw+tTG1Cy7u2JyAmUeo/4SrvqAPDO9ZMAAABfne7Tv8AAAQDAEgw\n" \
"RgIhAMqdhKLbXTticbpPcJN5OyUeWjARcZMGxywZbV0i7xrCAiEAujmd2dw6E8Pl\n" \
"i7Kkce5hDSbxwjSer/aYsX2ATZOjB7QAdgC3Pvsk35xNunXyOcW6WPRsXfxCz3qf\n" \
"NcSeHQmBJe20mQAAAX53u07sAAAEAwBHMEUCIQCJ/zubC4BS9693NVK+W6URi0lh\n" \
"NBuOIRNPpIHRmjJ0qQIgT+NK2Z7uQ94IJjJcKAIdQR3UEdN4aFRq2WyD7e7hFBww\n" \
"DQYJKoZIhvcNAQELBQADggEBABsf8AOcTMA/BtBkRLXEhrTI/h76I/BhHEP1ROMT\n" \
"eLbI3dA5sn36iWEds/I50Av/e4nyWHS6curB7hv0uAuOOh5/UUTEObCA4OypCRji\n" \
"i5wa2HMF7ICUgIpjr1tDYLq5YAXCWgJzOmtAqEVA9G/QjJkRT7F2Xaws5tfXwMOE\n" \
"Zn1rO5dgZmtgoIw0xLG28jBIjz5iHADqPU+l9/TmsX5fjGg4/I1to4vRvSD+8QYz\n" \
"Xq4RaIhBDkfJ4BEd2w2W/LdWdrBO4rmXeegvsN7vVBW20YBh19EB7Qf099EO8Qoi\n" \
"Zen2PaP5dDSloNOBs6wLj8EZ+O+dlDyI+KWEBYuh13bZkpM=\n" \
"-----END CERTIFICATE-----\n";
