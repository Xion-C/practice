def first_upper(astring):
    assert isinstance(astring, str) and len(astring) > 0
    result = astring[0].upper()
    assert isinstance(result, str) and len(result) == 1
    assert result == result.upper()
    return result
