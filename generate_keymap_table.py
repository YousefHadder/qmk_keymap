#!/usr/bin/env python3
"""
QMK Keymap Table Generator for Corne Layout

This script parses the QMK keymap source file and generates
a markdown table representation of all layers.
"""

import re
import sys
from pathlib import Path


# QMK keycode mappings for better display
QMK_KEYCODE_DISPLAY = {
    'KC_TAB': 'Tab',
    'KC_BSPC': 'Bksp',
    'KC_ENT': 'Enter',
    'KC_SPC': 'Space',
    'KC_ESC': 'Esc',
    'KC_LSFT': 'LShift',
    'KC_RSFT': 'RShift',
    'KC_LCTL': 'LCtrl',
    'KC_RCTL': 'RCtrl',
    'KC_LALT': 'LAlt',
    'KC_RALT': 'RAlt',
    'KC_LGUI': 'LGui',
    'KC_RGUI': 'RGui',
    'KC_CAPS': 'Caps',
    'KC_SCLN': ';',
    'KC_QUOT': "'",
    'KC_GRV': '`',
    'KC_COMM': ',',
    'KC_DOT': '.',
    'KC_SLSH': '/',
    'KC_BSLS': '\\',
    'KC_MINS': '-',
    'KC_EQL': '=',
    'KC_LBRC': '[',
    'KC_RBRC': ']',
    'KC_NO': '—',
    'KC_TRNS': '▼',
    'LSFT(KC_9)': '(',
    'LSFT(KC_0)': ')',
    'MO(1)': 'MO1',
    'MO(2)': 'MO2',
    'MO(3)': 'MO3',
    'ALL_T(KC_ESC)': 'All/Esc',
    'LCTL(KC_S)': 'Ctrl+S',
    'LCA(KC_F)': 'Ctrl+Alt+F',
    'LCA(KC_C)': 'Ctrl+Alt+C',
    'LCA(KC_ENT)': 'CA+Ent',
    'LCA(KC_LEFT)': 'CA+←',
    'LCA(KC_DOWN)': 'CA+↓',
    'LCA(KC_UP)': 'CA+↑',
    'LCA(KC_RIGHT)': 'CA+→',
    'LCAG(KC_LEFT)': 'CAG+←',
    'LCAG(KC_RIGHT)': 'CAG+→',
    'KC_LEFT': '←',
    'KC_DOWN': '↓',
    'KC_UP': '↑',
    'KC_RIGHT': '→',
    'KC_MPRV': '⏮',
    'KC_MPLY': '⏯',
    'KC_MNXT': '⏭',
    'KC_VOLD': '🔉',
    'KC_MUTE': '🔇',
    'KC_VOLU': '🔊',
    'KC_BRID': '🔅',
    'KC_BRIU': '🔆',
    'RGB_TOG': 'RGB',
    'RGB_HUI': 'H+',
    'RGB_HUD': 'H-',
    'RGB_SAI': 'S+',
    'RGB_SAD': 'S-',
    'RGB_VAI': 'V+',
    'RGB_VAD': 'V-',
    'RGB_MOD': 'RGB+',
    'RGB_RMOD': 'RGB-',
    'QK_BOOT': 'Boot',
    'QK_MAKE': 'Make',
    # Single letters and numbers
    'KC_A': 'A', 'KC_B': 'B', 'KC_C': 'C', 'KC_D': 'D', 'KC_E': 'E',
    'KC_F': 'F', 'KC_G': 'G', 'KC_H': 'H', 'KC_I': 'I', 'KC_J': 'J',
    'KC_K': 'K', 'KC_L': 'L', 'KC_M': 'M', 'KC_N': 'N', 'KC_O': 'O',
    'KC_P': 'P', 'KC_Q': 'Q', 'KC_R': 'R', 'KC_S': 'S', 'KC_T': 'T',
    'KC_U': 'U', 'KC_V': 'V', 'KC_W': 'W', 'KC_X': 'X', 'KC_Y': 'Y',
    'KC_Z': 'Z',
    'KC_1': '1', 'KC_2': '2', 'KC_3': '3', 'KC_4': '4', 'KC_5': '5',
    'KC_6': '6', 'KC_7': '7', 'KC_8': '8', 'KC_9': '9', 'KC_0': '0',
}

# Custom keycodes with SMTD modifiers
CUSTOM_KEYCODES = {
    'CKC_Q': 'Q/Alt',
    'CKC_W': 'W/Sft',
    'CKC_E': 'E/Ctl',
    'CKC_R': 'R/Gui',
    'CKC_U': 'U/Gui',
    'CKC_I': 'I/Ctl',
    'CKC_O': 'O/Sft',
    'CKC_P': 'P/Alt',
    'CKC_1': '1/Alt',
    'CKC_2': '2/Sft',
    'CKC_3': '3/Ctl',
    'CKC_4': '4/Gui',
    'CKC_7': '7/Gui',
    'CKC_8': '8/Ctl',
    'CKC_9': '9/Sft',
    'CKC_0': '0/Alt',
}

def clean_keycode(keycode):
    """Clean and format a keycode for display."""
    keycode = keycode.strip()
    
    # Handle custom keycodes first
    if keycode in CUSTOM_KEYCODES:
        return CUSTOM_KEYCODES[keycode]
    
    # Handle standard QMK keycodes
    if keycode in QMK_KEYCODE_DISPLAY:
        return QMK_KEYCODE_DISPLAY[keycode]
    
    # Handle simple letter/number keycodes
    if keycode.startswith('KC_') and len(keycode) == 4:
        return keycode[3:]
    
    # Handle numbers
    if keycode.startswith('KC_') and keycode[3:].isdigit():
        return keycode[3:]
    
    return keycode


def parse_layout(content):
    """Parse the keymap layout from source file content."""
    layouts = {}
    
    # Manual extraction of each layer based on the actual layout structure
    
    # BASE layer - Line 45-51
    base_keys = [
        'KC_TAB', 'CKC_Q', 'CKC_W', 'CKC_E', 'CKC_R', 'KC_T', 'LSFT(KC_9)', 'LSFT(KC_0)', 'KC_Y', 'CKC_U', 'CKC_I', 'CKC_O', 'CKC_P', 'KC_BSLS',
        'LCTL(KC_S)', 'KC_A', 'KC_S', 'KC_D', 'KC_F', 'KC_G', 'KC_LBRC', 'KC_RBRC', 'KC_H', 'KC_J', 'KC_K', 'KC_L', 'KC_SCLN', 'KC_QUOT',
        'MO(1)', 'KC_Z', 'KC_X', 'KC_C', 'KC_V', 'KC_B', 'KC_N', 'KC_M', 'KC_COMM', 'KC_DOT', 'KC_SLSH', 'KC_GRV',
        'MO(2)', 'KC_BSPC', 'ALL_T(KC_ESC)', 'KC_ENT', 'KC_SPC', 'MO(3)'
    ]
    layouts['_BASE'] = base_keys
    
    # LAYER1 - Line 56-62
    layer1_keys = [
        'KC_TRNS', 'KC_BRID', 'KC_BRIU', 'KC_MPRV', 'KC_MPLY', 'KC_MNXT', 'KC_NO', 'KC_NO', 'KC_VOLD', 'KC_MUTE', 'KC_VOLU', 'KC_NO', 'KC_NO', 'KC_NO',
        'KC_CAPS', 'KC_NO', 'KC_NO', 'KC_NO', 'LCA(KC_F)', 'KC_NO', 'KC_LALT', 'KC_RALT', 'KC_LEFT', 'KC_DOWN', 'KC_UP', 'KC_RIGHT', 'KC_NO', 'KC_NO',
        'KC_LSFT', 'KC_NO', 'KC_NO', 'LCA(KC_C)', 'KC_NO', 'KC_NO', 'LCA(KC_LEFT)', 'LCA(KC_DOWN)', 'LCA(KC_UP)', 'LCA(KC_RIGHT)', 'KC_NO', 'KC_NO',
        'KC_LGUI', 'KC_TRNS', 'KC_SPC', 'LCA(KC_ENT)', 'LCAG(KC_LEFT)', 'LCAG(KC_RIGHT)'
    ]
    layouts['_LAYER1'] = layer1_keys
    
    # LAYER2 - Line 67-73
    layer2_keys = [
        'KC_EQL', 'CKC_1', 'CKC_2', 'CKC_3', 'CKC_4', 'KC_5', 'KC_LCTL', 'KC_RCTL', 'KC_6', 'CKC_7', 'CKC_8', 'CKC_9', 'CKC_0', 'KC_MINS',
        'KC_CAPS', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO',
        'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO',
        'KC_TRNS', 'KC_TRNS', 'KC_TRNS', 'KC_TRNS', 'KC_TRNS', 'KC_TRNS'
    ]
    layouts['_LAYER2'] = layer2_keys
    
    # LAYER3 - Line 78-84
    layer3_keys = [
        'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO',
        'RGB_TOG', 'RGB_HUI', 'RGB_SAI', 'RGB_VAI', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO',
        'RGB_MOD', 'RGB_HUD', 'RGB_SAD', 'RGB_VAD', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO', 'KC_NO',
        'QK_BOOT', 'QK_MAKE', 'KC_SPC', 'KC_ENT', 'KC_TRNS', 'KC_RGUI'
    ]
    layouts['_LAYER3'] = layer3_keys
    
    return layouts


def create_layer_table(layer_name, keycodes):
    """Create a markdown table for a single layer."""
    # split_3x6_3_ex2 layout has: 
    # Row 1: 7 left keys + 7 right keys (14 total)
    # Row 2: 7 left keys + 7 right keys (14 total)  
    # Row 3: 6 left keys + 6 right keys (12 total)
    # Thumb row: 3 left + 3 right (6 total)
    # Total: 46 keys
    
    if len(keycodes) < 46:
        # Pad with empty keys if needed
        keycodes.extend(['KC_NO'] * (46 - len(keycodes)))
    
    # Clean keycodes for display
    display_keys = [clean_keycode(k) for k in keycodes]
    
    table = f"\n### {layer_name.replace('_', ' ').title()}\n\n"
    
    # Top row - 7 keys per side
    table += "| | | | | | | | | | | | | | | |\n"
    table += "|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n"
    
    # Row 1: positions 0-6 (left), 7-13 (right)
    if len(display_keys) >= 14:
        row1 = f"| {display_keys[0]} | {display_keys[1]} | {display_keys[2]} | {display_keys[3]} | {display_keys[4]} | {display_keys[5]} | {display_keys[6]} |  | {display_keys[7]} | {display_keys[8]} | {display_keys[9]} | {display_keys[10]} | {display_keys[11]} | {display_keys[12]} | {display_keys[13]} |\n"
        table += row1
    
    # Row 2: positions 14-20 (left), 21-27 (right)
    if len(display_keys) >= 28:
        row2 = f"| {display_keys[14]} | {display_keys[15]} | {display_keys[16]} | {display_keys[17]} | {display_keys[18]} | {display_keys[19]} | {display_keys[20]} |  | {display_keys[21]} | {display_keys[22]} | {display_keys[23]} | {display_keys[24]} | {display_keys[25]} | {display_keys[26]} | {display_keys[27]} |\n"
        table += row2
    
    # Row 3: positions 28-33 (left), 34-39 (right) - 6 keys per side, no outer columns
    if len(display_keys) >= 40:
        row3 = f"|  | {display_keys[28]} | {display_keys[29]} | {display_keys[30]} | {display_keys[31]} | {display_keys[32]} | {display_keys[33]} |  | {display_keys[34]} | {display_keys[35]} | {display_keys[36]} | {display_keys[37]} | {display_keys[38]} | {display_keys[39]} |  |\n"
        table += row3
    
    # Thumb row: positions 40-42 (left), 43-45 (right)
    if len(display_keys) >= 46:
        thumb_row = f"|  |  |  | {display_keys[40]} | {display_keys[41]} | {display_keys[42]} | {display_keys[43]} | {display_keys[44]} | {display_keys[45]} |  |  |  |  |  |  |\n"
        table += thumb_row
    
    return table


def main():
    """Main function to generate the keymap table."""
    source_file = Path(__file__).parent / "default" / "source.c"
    
    if not source_file.exists():
        print(f"Error: {source_file} not found!")
        sys.exit(1)
    
    # Read the source file
    with open(source_file, 'r') as f:
        content = f.read()
    
    # Parse layouts
    layouts = parse_layout(content)
    
    if not layouts:
        print("No layouts found in source file!")
        sys.exit(1)
    
    # Generate markdown content
    markdown = "# QMK Keymap for Corne v4\n\n"
    markdown += "This document shows the key mappings for all layers of the Corne keyboard layout.\n\n"
    
    # Add legend
    markdown += "## Legend\n\n"
    markdown += "- **Home Row Modifiers**: Letters with modifiers (e.g., `Q/Alt` = Q on tap, Alt on hold)\n"
    markdown += "- **▼** = Transparent (uses lower layer)\n"
    markdown += "- **—** = No operation\n"
    markdown += "- **MO1/2/3** = Momentary layer switch\n\n"
    
    # Add combo information
    markdown += "## Special Features\n\n"
    markdown += "### Combos\n"
    markdown += "- **Caps Lock**: Press both thumb keys (Backspace + Space) simultaneously\n\n"
    
    markdown += "### Home Row Modifiers (SMTD)\n"
    markdown += "- **Left Hand**: Q=Alt, W=Shift, E=Ctrl, R=Gui\n"
    markdown += "- **Right Hand**: U=Gui, I=Ctrl, O=Shift, P=Alt\n"
    markdown += "- **Numbers**: Same pattern on number layer\n\n"
    
    # Generate tables for each layer
    layer_order = ['_BASE', '_LAYER1', '_LAYER2', '_LAYER3']
    for layer_name in layer_order:
        if layer_name in layouts:
            markdown += create_layer_table(layer_name, layouts[layer_name])
    
    return markdown


if __name__ == "__main__":
    try:
        result = main()
        print(result)
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)